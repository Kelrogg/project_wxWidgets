#include "pch.hpp"

#include "Model/Document/Elements/Text/Paragraph.hpp"

const std::string &Paragraph::GetText() const noexcept
{
	return m_text;
}

void Paragraph::SetText(const std::string &text)
{
	m_text = text;
}
