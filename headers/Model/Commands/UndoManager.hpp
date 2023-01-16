#ifndef COMMAND_COMMANDS_UNDO_MANAGER_HPP
#define COMMAND_COMMANDS_UNDO_MANAGER_HPP

#include "CompoundEdit.hpp"

class UndoManager : private CompoundEdit
{
public:
	using CompoundEdit::Undo;
	using CompoundEdit::Redo;

	UndoManager() = default;

	bool CanUndo() const final;
	bool CanRedo() const final;

	void AddAndExecuteEdit(const IUndoableEditSharedPtr& edit);

private:
	bool DerivedExecute() final;
	bool DerivedUndo() final;
	bool DerivedRedo() final;

	size_t m_nextEditIndex{};
};

#endif
