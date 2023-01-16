#ifndef COMMAND_DOCUMENT_ELEMENTS_IPARAGRAPH_HPP
#define COMMAND_DOCUMENT_ELEMENTS_IPARAGRAPH_HPP

#include "IElement.hpp"
#include "IParagraph_fwd.hpp"

class IParagraph : public IElement
{
public:
	virtual const std::string& GetText() const noexcept = 0;
	virtual void SetText(const std::string& text) = 0;
};

#endif
