#ifndef COMMAND_DOCUMENT_COMMANDS_INSERT_DOCUMENT_ITEM_HPP
#define COMMAND_DOCUMENT_COMMANDS_INSERT_DOCUMENT_ITEM_HPP

#include "../../Commands/AbstractUndoableEdit.hpp"
#include "../Elements/DocumentItem.hpp"
#include "common.hpp"

template <typename DocumentInnerContainerT>
class CInsertDocumentItem : public AbstractUndoableEdit
{
public:
	CInsertDocumentItem(DocumentInnerContainerT& target, const DocumentItem& docItem, size_t index)
		: AbstractUndoableEdit(document_commands::INSERT_DOCUMENT_ITEM_COMMAND_NAME)
		, m_target(target)
		, m_index(index)
		, m_state(docItem)
	{
	}

private:
	bool DerivedExecute() final
	{
		if (m_index > m_target.size())
		{
			throw std::out_of_range("Failed to insert an item into Document. Given index is out of range");
		}

		auto it = m_target.begin();
		std::advance(it, m_index);

		m_target.emplace(it, m_state);

		return true;
	}

	bool DerivedUndo() final
	{
		auto it = m_target.begin();
		std::advance(it, m_index);

		m_target.erase(it);

		return true;
	}

	bool DerivedRedo() final
	{
		return DerivedExecute();
	}

	DocumentInnerContainerT& m_target;

	size_t m_index;
	DocumentItem m_state;
};

#endif
