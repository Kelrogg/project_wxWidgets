#include "pch.hpp"

#include "Model/Commands/UndoManager.hpp"

bool UndoManager::CanUndo() const
{
	return m_nextEditIndex != 0;
}

bool UndoManager::CanRedo() const
{
	return m_nextEditIndex != m_edits.size();
}

void UndoManager::AddAndExecuteEdit(const IUndoableEditSharedPtr &edit)
{
	if (m_nextEditIndex < m_edits.size())
	{
		edit->Execute();

		m_edits.resize(++m_nextEditIndex);
		m_edits.back() = edit;
	}
	else
	{
		m_edits.emplace_back(nullptr);

		try
		{
			edit->Execute();

			m_edits.back() = edit;
			++m_nextEditIndex;
		}
		catch (...)
		{
			m_edits.pop_back();
			throw;
		}
	}
}

bool UndoManager::DerivedExecute()
{
	return false;
}

bool UndoManager::DerivedUndo()
{
	m_edits[--m_nextEditIndex]->Undo();

	return true;
}

bool UndoManager::DerivedRedo()
{
	m_edits[m_nextEditIndex++]->Redo();

	return true;
}
