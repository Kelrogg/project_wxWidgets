#include "pch.hpp"

#include "Model/Document/Elements/Shapes/Rectangle.hpp"

const Point &Rectangle::GetLeftTop() const noexcept
{
	return GetBasePoint();
}

const Point &Rectangle::GetRightBottom() const noexcept
{
	return m_rightBottom;
}

void Rectangle::Draw(const ICanvasSharedPtr &canvas) const
{
	auto &leftTopP = GetLeftTop();
	auto &rightBottomP = GetRightBottom();

	auto centerX = (rightBottomP.x + leftTopP.x) / 2;
	auto centerY = (rightBottomP.y + leftTopP.y) / 2;

	auto width = rightBottomP.x - leftTopP.x;
	auto height = leftTopP.y - rightBottomP.y;

	// canvas->SetColor(GetColor());
	canvas->DrawRectangle(centerX, centerY, width, height, 0.0);
}
