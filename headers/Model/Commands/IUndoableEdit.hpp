#ifndef COMMAND_COMMANDS_IUNDOABLE_EDIT_HPP
#define COMMAND_COMMANDS_IUNDOABLE_EDIT_HPP

#include "Model/Document/Commands/common.hpp"
#include "IUndoableEdit_fwd.hpp"

class IUndoableEdit
{
public:
	virtual void Execute() = 0;

	virtual bool CanUndo() const = 0;
	virtual bool CanRedo() const = 0;

	virtual void Undo() = 0;
	virtual void Redo() = 0;
	virtual void Destroy() = 0;

	virtual bool AddEdit(const IUndoableEditSharedPtr &edit) = 0;
	virtual bool ReplaceEdit(const IUndoableEditSharedPtr &edit) = 0;

	virtual CommandName GetName() const = 0;

	virtual void operator()() = 0;

	virtual ~IUndoableEdit() = default;
};

#endif
