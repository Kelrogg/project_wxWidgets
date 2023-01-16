#ifndef COMMAND_DOCUMENT_ELEMENTS_IIMAGE_HPP
#define COMMAND_DOCUMENT_ELEMENTS_IIMAGE_HPP

#include "../common.hpp"
#include "IElement.hpp"
#include "Image_fwd.hpp"

class IImage : public IElement
{
public:
	using StdPath = document_elements_common::StdPath;

	virtual const StdPath& GetPath() const = 0;
	virtual const std::string& GetName() const = 0;

	virtual size_t GetWidth() const = 0;
	virtual size_t GetHeight() const = 0;

	virtual void Resize(size_t width, size_t height) = 0;

	virtual void Save(const StdPath& path) const = 0;
};

#endif
