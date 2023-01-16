#ifndef CANVAS_ICANVAS_HPP
#define CANVAS_ICANVAS_HPP

#include "Document/Elements/Shapes/Color.hpp"
#include "Document/Elements/Shapes/Point.hpp"

class ICanvas
{
public:
	virtual void DrawLine(const Point& from, const Point& to) = 0;
	virtual void DrawEllipse(const Point& center, double verticalR, double horizontalRadius) = 0;
	virtual void DrawRegularPolygon(const std::vector<Point>& points) = 0;
	virtual void SetColor(Color color) = 0;

	virtual ~ICanvas() = default;
};

using ICanvasSharedPtr = std::shared_ptr<ICanvas>;

#endif
