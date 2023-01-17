#ifndef COMMAND_DOCUMENT_ELEMENTS_DOCUMENT_ITEM_HPP
#define COMMAND_DOCUMENT_ELEMENTS_DOCUMENT_ITEM_HPP

#include "IImage.hpp"
#include "IParagraph.hpp"
#include "Shapes/IShape.hpp"

class DocumentItem
{
public:
	DocumentItem(const IElementSharedPtr &ptr);

	IShapeSharedPtr GetShape();
	IShapeSharedPtrConst GetShape() const;
	IImageSharedPtr GetImage();
	IImageSharedPtrConst GetImage() const;
	IParagraphSharedPtr GetParagraph();
	IParagraphSharedPtrConst GetParagraph() const;

private:
	IElementSharedPtr m_element;
};

#endif
