#ifndef COMMAND_DOCUMENT_COMMANDS_CSET_TITLE_HPP
#define COMMAND_DOCUMENT_COMMANDS_CSET_TITLE_HPP

#include "../../Commands/AbstractUndoableEdit.hpp"
#include "common.hpp"

class CSetTitle : public AbstractUndoableEdit
{
public:
	template <typename StringT = std::string>
	CSetTitle(std::string& target, StringT&& name)
		: AbstractUndoableEdit(document_commands::SET_TITLE_COMMAND_NAME)
		, m_target(target)
		, m_state(std::forward<StringT>(name))
	{
	}

private:
	bool DerivedExecute() final;

	bool DerivedUndo() final;
	bool DerivedRedo() final;

	std::string& m_target;
	std::string m_state;
};

#endif
