#ifndef COMMAND_DOCUMENT_ELEMENTS_IPARAGRAPH_HPP
#define COMMAND_DOCUMENT_ELEMENTS_IPARAGRAPH_HPP

#include "Model/Document/Elements/IElement.hpp"
#include "Model/Document/Elements/Text/IParagraph_fwd.hpp"

class IParagraph : public IElement
{
public:
	virtual const std::string &GetText() const noexcept = 0;
	virtual void SetText(const std::string &text) = 0;
};

#endif
