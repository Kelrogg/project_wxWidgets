#ifndef COMMAND_DOCUMENT_MODEL_HPP
#define COMMAND_DOCUMENT_MODEL_HPP

#include "Model/Commands/UndoManager.hpp"
#include "Model/Document/Elements/DocumentItem.hpp"
#include "Model/Document/Elements/Images/IImage.hpp"
#include "Model/Document/Elements/Text/IParagraph.hpp"
#include "Model/Document/IDocument.hpp"
#include "Model/Document/Elements/IElement.hpp"

#include <wx/graphics.h>
#include <wx/dcbuffer.h>

class Model : public IDocument
{
public:
	// using Container = std::list<DocumentItem>;

	Model() = default;

	// IParagraphSharedPtr InsertParagraph(const std::string &text,
	//									std::optional<size_t> position = std::nullopt) final;
	// IParagraphSharedPtr ReplaceParagraph(const std::string &newText,
	//									 std::optional<size_t> position = std::nullopt) final;

	//	IImageSharedPtr InsertImage(const Path &path, size_t width, size_t height,
	//								std::optional<size_t> position = std::nullopt) final;
	//	IImageSharedPtr ResizeImage(size_t width, size_t height,
	//								std::optional<size_t> position = std::nullopt) final;
	//
	//	size_t GetItemsCount() const final;
	//	const DocumentItem &GetItem(size_t index) const final;
	//
	//	void DeleteItem(size_t index) final;
	//
	//	const std::string &GetTitle() const final;
	void SetTitle(const std::string &title) final;
	//
	//	bool CanUndo() const final;
	//	void Undo() final;
	//	bool CanRedo() const final;
	//	void Redo() final;
	//
	//	void Save(const StdPath &path) const final;
	//
	//	Iterator begin() final;
	//	ConstIterator begin() const final;

private:
	//	size_t CountImages() const;

	std::string m_title = "Title";

	// Container m_items;
	//  UndoManager m_undoManager;
};

#endif
