#ifndef CANVAS_ICANVAS_HPP
#define CANVAS_ICANVAS_HPP

#include "Model/Document/Elements/Shapes/Color.hpp"
#include "Model/Document/Elements/Shapes/Point.hpp"

class ICanvas
{
public:
	// virtual void DrawLine(double fromX, double fromY, double toX, double toY) = 0;
	virtual void DrawRectangle(double centerX, double centerY, double width, double height, double angle) = 0;
	// virtual void DrawEllipse(double centerX, double centerY, double verticalR, double horizontalR, double angle) = 0;
	// virtual void DrawRegularPolygon(const std::vector<Point> &points) = 0;
	//  virtual void SetColor(Color color) = 0;

	virtual ~ICanvas() = default;
};

using ICanvasSharedPtr = std::shared_ptr<ICanvas>;

#endif
