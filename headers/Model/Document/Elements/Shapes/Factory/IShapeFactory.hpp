#ifndef SHAPES_FACTORY_ISHAPE_FACTORY_HPP
#define SHAPES_FACTORY_ISHAPE_FACTORY_HPP

#include "../IShape.hpp"

class IShapeFactory
{
public:
	virtual ShapeSharedPtr CreateRectangle(Point &&leftTop, double width, double height, Color color) const = 0;
	// virtual ShapeSharedPtr CreateTriangle(Point &&v1, Point &&v2, Point &&v3, Color color) const = 0;
	// virtual ShapeSharedPtr CreateEllipse(Point &&basePoint, double verticalR, double horizontalR, Color color) const = 0;

	virtual ~IShapeFactory() = default;
};

using IShapeFactorySharedPtr = std::shared_ptr<IShapeFactory>;

#endif
