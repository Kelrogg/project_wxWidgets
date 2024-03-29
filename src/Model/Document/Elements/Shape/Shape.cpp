#include "pch.hpp"

#include "Model/Document/Elements/Shapes/Shape.hpp"

const Point &Shape::GetBasePoint() const noexcept
{
	return m_basePoint;
}

Color Shape::GetColor() const noexcept
{
	return m_color;
}
