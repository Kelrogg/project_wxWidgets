#ifndef COMMAND_DOCUMENT_ELEMENTS_PARAGRAPH_HPP
#define COMMAND_DOCUMENT_ELEMENTS_PARAGRAPH_HPP

#include "IParagraph.hpp"

class Paragraph final : public IParagraph
{
public:
	template <typename StringT = std::string>
	Paragraph(StringT &&text)
		: m_text(std::forward<StringT>(text))
	{
	}

	const std::string &GetText() const noexcept final;
	void SetText(const std::string &text) final;

private:
	std::string m_text{};
};

#endif
