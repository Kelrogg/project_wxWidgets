#include "pch.hpp"

#include "Document/Elements/DocumentItem.hpp"

DocumentItem::DocumentItem(const IElementSharedPtr &ptr)
	: m_element(ptr)
{
}

IImageSharedPtr DocumentItem::GetImage()
{
	auto ptr = std::dynamic_pointer_cast<IImage>(m_element);
	if (ptr)
	{
		return ptr;
	}
	return nullptr;
}

IImageSharedPtrConst DocumentItem::GetImage() const
{
	auto ptr = std::dynamic_pointer_cast<const IImage>(m_element);
	if (ptr)
	{
		return ptr;
	}
	return nullptr;
}

IParagraphSharedPtr DocumentItem::GetParagraph()
{
	auto ptr = std::dynamic_pointer_cast<IParagraph>(m_element);
	if (ptr)
	{
		return ptr;
	}
	return nullptr;
}

IParagraphSharedPtrConst DocumentItem::GetParagraph() const
{
	auto ptr = std::dynamic_pointer_cast<const IParagraph>(m_element);
	if (ptr)
	{
		return ptr;
	}
	return nullptr;
}
