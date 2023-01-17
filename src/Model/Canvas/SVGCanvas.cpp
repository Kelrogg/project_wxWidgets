#include "pch.hpp"

#include "Canvas/SVGCanvas.hpp"

SVGCanvas::SVGCanvas(const wxString& outputFileName, double width, double height)
	: m_svgFile(outputFileName, width, height)
{
}

void SVGCanvas::DrawEllipse(const Point& center, double verticalR, double horizontalRadius)
{
	m_svgFile.DrawEllipse(center.x, center.y, verticalR * 2, horizontalRadius * 2);
}

void SVGCanvas::DrawLine(const Point& from, const Point& to)
{
	m_svgFile.DrawLine(from.x, from.y, to.x, to.y);
}

void SVGCanvas::DrawRegularPolygon(const std::vector<Point>& points)
{
	std::vector<wxPoint> wxPoints{};
	wxPoints.reserve(points.size());
	std::for_each(points.begin(), points.end(), [&wxPoints](auto& p) {
		wxPoints.emplace_back(wxPoint{ int(p.x), int(p.y) });
	});
	m_svgFile.DrawPolygon(points.size(), wxPoints.data());
}

const auto wxPINK_BRUSH = wxBrush(wxColor{ 255, 182, 193 });

decltype(auto) GetColoredBrush(Color color)
{
	switch (color)
	{
	case Color::BLACK:
		return wxBLACK_BRUSH;
	case Color::BLUE:
		return wxBLUE_BRUSH;
	case Color::GREEN:
		return wxGREEN_BRUSH;
	case Color::PINK:
		return &wxPINK_BRUSH;
	case Color::RED:
		return wxRED_BRUSH;
	case Color::YELLOW:
		return wxYELLOW_BRUSH;
	}
	return wxBLACK_BRUSH;
};

void SVGCanvas::SetColor(Color color)
{
	m_svgFile.SetBrush(*GetColoredBrush(color));
}

//wxBEGIN_EVENT_TABLE(SVGCanvas, wxFrame)
//wxEND_EVENT_TABLE()