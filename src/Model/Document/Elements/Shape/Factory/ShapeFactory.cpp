#include "pch.hpp"

#include "Document/Elements/Shapes/Factory/ShapeFactory.hpp"

#include "Document/Elements/Shapes/Ellipse.hpp"
#include "Document/Elements/Shapes/Rectangle.hpp"
#include "Document/Elements/Shapes/RegularPolygon.hpp"
#include "Document/Elements/Shapes/Triangle.hpp"
#include "Document/Elements/Shapes/ShapeType.hpp"

// template <typename Point = Point, typename Color = Color>
ShapeSharedPtr ShapeFactory::CreateEllipse(Point &&basePoint, double verticalR, double horizontalR, Color color) const
{
	return std::make_shared<Ellipse>(std::forward<Point>(basePoint), verticalR, horizontalR, color);
}

// template <typename Point = Point, typename Color = Color>
ShapeSharedPtr ShapeFactory::CreateRectangle(Point &&leftTop, double width, double height, Color color) const
{
	return std::make_shared<Rectangle>(std::forward<Point>(leftTop), width, height, color);
}

// template <typename Point = Point, typename Color = Color>
ShapeSharedPtr ShapeFactory::CreateTriangle(Point &&v1, Point &&v2, Point &&v3, Color color) const
{
	return std::make_shared<Triangle>(std::forward<Point>(v1), std::forward<Point>(v2), std::forward<Point>(v3), color);
}

template <typename Point = Point, typename Color = Color>
ShapeSharedPtr CreateRegularPolygon(Point &&p, Color color)
{
	double radius{};
	size_t vertexCount{};

	return std::make_shared<RegularPolygon>(p, radius, vertexCount, color);
}