#include "pch.hpp"

#include "Document/Elements/Shapes/Ellipse.hpp"

const Point& Ellipse::GetCenter() const noexcept
{
	return GetBasePoint();
}

double Ellipse::GetVerticalRadius() const
{
	return m_verticalR;
}

double Ellipse::GetHorizontalRadius() const
{
	return m_horizontalR;
}

void Ellipse::Draw(const ICanvasSharedPtr& canvas) const
{
	canvas->SetColor(GetColor());
	canvas->DrawEllipse(GetCenter(), GetVerticalRadius(), GetHorizontalRadius());
}
