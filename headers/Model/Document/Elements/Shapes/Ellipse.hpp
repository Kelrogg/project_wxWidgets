#ifndef SHAPES_CONCRETE_SHAPES_ELLIPSE_HPP
#define SHAPES_CONCRETE_SHAPES_ELLIPSE_HPP

#include "Shape.hpp"

class Ellipse : public Shape
{
public:
	template <typename Point = Point>
	Ellipse(Point &&basePoint, double verticalR, double horizontalR, Color color)
		: Shape(std::forward<Point>(basePoint), color), m_verticalR(verticalR), m_horizontalR(horizontalR)
	{
	}

	const Point &GetCenter() const noexcept;
	double GetVerticalRadius() const;
	double GetHorizontalRadius() const;

	void Draw(const ICanvasSharedPtr &canvas) const final;

private:
	double m_verticalR, m_horizontalR;
};

#endif