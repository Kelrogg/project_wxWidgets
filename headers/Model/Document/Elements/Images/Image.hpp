#ifndef COMMAND_DOCUMENT_ELEMENTS_IMAGE_HPP
#define COMMAND_DOCUMENT_ELEMENTS_IMAGE_HPP

#include "Model/Document/common.hpp"
#include "IImage.hpp"

constexpr auto MIN_DIMENSION_SIZE = 1;
constexpr auto MAX_DIMENSION_SIZE = 10000;

class Image : public IImage
{
public:
	Image(const StdPath &path, size_t width, size_t height);
	~Image();

	const StdPath &GetPath() const final;
	const std::string &GetName() const final;
	size_t GetWidth() const final;
	size_t GetHeight() const final;
	void Resize(size_t width, size_t height) final;

	void Save(const StdPath &path) const final;

private:
	std::string m_name;
	size_t m_width, m_height;

	mutable StdPath m_path;
};

#endif
