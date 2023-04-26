#ifndef COMMAND_COMMANDS_ABSTRACT_UNDOABLE_EDIT_HPP
#define COMMAND_COMMANDS_ABSTRACT_UNDOABLE_EDIT_HPP

#include "IUndoableEdit.hpp"
#include "Model/Document/Commands/common.hpp"

class AbstractUndoableEdit : public IUndoableEdit
{
public:
	void Execute() final;

	bool CanUndo() const override;
	bool CanRedo() const override;

	void Undo() override;
	void Redo() override;

	bool AddEdit(const IUndoableEditSharedPtr &edit) override;
	bool ReplaceEdit(const IUndoableEditSharedPtr &edit) override;

	CommandName GetName() const final;

	void operator()() final;

protected:
	AbstractUndoableEdit() = default;

	AbstractUndoableEdit(CommandName commandName)
		: m_wasExecuted(false), m_commandName(commandName)
	{
	}
	~AbstractUndoableEdit();

	virtual bool DerivedExecute() = 0;

	virtual bool DerivedUndo() = 0;
	virtual bool DerivedRedo() = 0;

	void Destroy() override;

private:
	bool m_wasExecuted;
	const CommandName m_commandName{};
};

#endif
