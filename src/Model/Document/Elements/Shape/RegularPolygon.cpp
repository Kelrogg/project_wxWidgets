#include "pch.hpp"

#include "Document/Elements/Shapes/RegularPolygon.hpp"

const Point& RegularPolygon::GetCenter() const noexcept
{
	return GetBasePoint();
}

double RegularPolygon::GetRadius() const noexcept
{
	return m_radius;
}

size_t RegularPolygon::GetVertexCount() const
{
	return m_points.size();
}

void RegularPolygon::Draw(const ICanvasSharedPtr& canvas) const
{
	canvas->SetColor(GetColor());
	canvas->DrawRegularPolygon(m_points);
}
