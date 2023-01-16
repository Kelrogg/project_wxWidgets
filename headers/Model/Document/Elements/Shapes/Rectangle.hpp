#ifndef SHAPES_CONCRETE_SHAPES_RECTANGLE_HPP
#define SHAPES_CONCRETE_SHAPES_RECTANGLE_HPP

#include "Shape.hpp"

class Rectangle : public Shape
{
public:
	template <typename Point = Point>
	Rectangle(Point &&leftTop, double width, double height, Color color)
		: Shape(std::forward<Point>(leftTop), color), m_rightBottom(leftTop.x + width, leftTop.y + height)
	{
	}

	const Point &GetLeftTop() const noexcept;
	const Point &GetRightBottom() const noexcept;

	void Draw(const ICanvasSharedPtr &canvas) const final;

private:
	Point m_rightBottom;
};

#endif
