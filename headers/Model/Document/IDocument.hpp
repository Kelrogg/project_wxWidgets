#ifndef COMMAND_DOCUMENT_HPP
#define COMMAND_DOCUMENT_HPP

#include "Model/Iterator/Iterator.hpp"
#include "Model/Document/Elements/DocumentItem.hpp"
#include "Model/Document/Elements/Images/IImage.hpp"
#include "Model/Document/Elements/Text/IParagraph.hpp"

#include "Model/Document/IDocument_fwd.hpp"
#include "Model/Document/common.hpp"

class IDocument
{
public:
	using Path = document_elements_common::StdPath;
	using Iterator = IIteratorSharedPtr<DocumentItem>;
	using ConstIterator = IIteratorSharedPtr<const DocumentItem>;

	virtual void SetTitle(const std::string &title) = 0;
	// virtual const std::string &GetTitle() const = 0;

	// virtual IParagraphSharedPtr InsertParagraph(const std::string &text,
	// 											std::optional<size_t> position = std::nullopt) = 0;
	// virtual IParagraphSharedPtr ReplaceParagraph(const std::string &newText,
	// 											 std::optional<size_t> position = std::nullopt) = 0;

	// virtual IImageSharedPtr InsertImage(const Path &path, size_t width, size_t height,
	// 									std::optional<size_t> position = std::nullopt) = 0;
	// virtual IImageSharedPtr ResizeImage(size_t width, size_t height,
	// 									std::optional<size_t> position = std::nullopt) = 0;

	// virtual size_t GetItemsCount() const = 0;
	// virtual const DocumentItem &GetItem(size_t index) const = 0;

	// virtual void DeleteItem(size_t index) = 0;

	// virtual bool CanUndo() const = 0;
	// virtual void Undo() = 0;
	// virtual bool CanRedo() const = 0;
	// virtual void Redo() = 0;

	// virtual void Save(const Path &path) const = 0;

	// virtual Iterator begin() = 0;
	// virtual ConstIterator begin() const = 0;

	// virtual ~IDocument() = default;
};

namespace document_item_types
{

	constexpr auto PARAGRAPH_TYPE_STR = "Paragraph";
	constexpr auto IMAGE_TYPE_STR = "Image";

};

#endif
