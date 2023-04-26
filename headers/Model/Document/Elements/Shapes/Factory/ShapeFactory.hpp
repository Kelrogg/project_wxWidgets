#ifndef SHAPES_FACTORY_SHAPE_FACTORY_H
#define SHAPES_FACTORY_SHAPE_FACTORY_H

#include "IShapeFactory.hpp"

class ShapeFactory : public IShapeFactory
{
public:
	ShapeSharedPtr CreateRectangle(Point &&leftTop, double width, double height, Color color) const override;
	// ShapeSharedPtr CreateTriangle(Point &&v1, Point &&v2, Point &&v3, Color color) const override;
	// ShapeSharedPtr CreateEllipse(Point &&basePoint, double verticalR, double horizontalR, Color color) const override;
};

#endif