#ifndef SHAPES_CONCRETE_SHAPES_REGULAR_POLYGON_HPP
#define SHAPES_CONCRETE_SHAPES_REGULAR_POLYGON_HPP

#include "Shape.hpp"
#include "Util/RegularPolygonVertexesCreator.hpp"

class RegularPolygon : public Shape
{
public:
	template <typename Point = Point>
	RegularPolygon(Point&& center, double radius, size_t vertexCount, Color color)
		: Shape(center, color)
		, m_points(std::move(CreateRegularPolygonVertexes(std::forward<Point>(center), radius, vertexCount)))
		, m_radius(radius)
	{
	}

	const Point& GetCenter() const noexcept;
	double GetRadius() const noexcept;
	size_t GetVertexCount() const;

	void Draw(const ICanvasSharedPtr& canvas) const final;

private:
	double m_radius;
	std::vector<Point> m_points;
};

#endif
