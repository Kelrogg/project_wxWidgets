#ifndef COMMAND_DOCUMENT_ELEMENTS_IELEMENT_HPP
#define COMMAND_DOCUMENT_ELEMENTS_IELEMENT_HPP

#include "IElement_fwd.hpp"

class IElement
{
public:
	virtual ~IElement() = default;

	// Resize
	void Move();
	// Rotate
};

#endif
