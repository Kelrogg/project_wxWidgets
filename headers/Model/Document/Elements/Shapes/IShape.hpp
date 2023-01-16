#ifndef SHAPES_ISHAPE_HPP
#define SHAPES_ISHAPE_HPP

#include "../IElement.hpp"
#include "../../../Canvas/ICanvas.hpp"

#include "Point.hpp"
#include "Color.hpp"

class IShape : public IElement
{
public:
	virtual void Draw(const ICanvasSharedPtr &canvas) const = 0;
	virtual const Point &GetBasePoint() const noexcept = 0;
	virtual Color GetColor() const noexcept = 0;

	virtual ~IShape() = default;
};

using ShapeSharedPtr = std::shared_ptr<IShape>;

#endif