#include "pch.hpp"

#include <wx/graphics.h>
#include <wx/dcbuffer.h>

#include "Model/Canvas/WXCanvas.hpp"

wxDEFINE_EVENT(CANVAS_RECT_ADDED, wxCommandEvent);
wxDEFINE_EVENT(CANVAS_RECT_REMOVED, wxCommandEvent);
wxDEFINE_EVENT(CANVAS_ELLIPSE_ADDED, wxCommandEvent);
wxDEFINE_EVENT(CANVAS_ELLIPSE_REMOVED, wxCommandEvent);
wxDEFINE_EVENT(CANVAS_TRIANGLE_ADDED, wxCommandEvent);
wxDEFINE_EVENT(CANVAS_TRIANGLE_REMOVED, wxCommandEvent);

WXCanvas::WXCanvas(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size) : wxWindow(parent, id, pos, size)
{
	this->SetBackgroundStyle(wxBG_STYLE_PAINT); // needed for windows

	this->Bind(wxEVT_PAINT, &WXCanvas::OnPaint, this);
	this->Bind(wxEVT_LEFT_DOWN, &WXCanvas::OnMouseDown, this);
	this->Bind(wxEVT_MOTION, &WXCanvas::OnMouseMove, this);
	this->Bind(wxEVT_LEFT_UP, &WXCanvas::OnMouseUp, this);
	this->Bind(wxEVT_LEAVE_WINDOW, &WXCanvas::OnMouseLeave, this);

	// DELETE
	DrawRectangle(this->FromDIP(333), this->FromDIP(444), this->FromDIP(70), this->FromDIP(50), 0.0);
	DrawRectangle(this->FromDIP(450), this->FromDIP(250), this->FromDIP(80), this->FromDIP(90), M_PI / 3.0);
	DrawRectangle(this->FromDIP(300), this->FromDIP(200), this->FromDIP(100), this->FromDIP(160), -M_PI / 4.0);

	this->draggedObj = nullptr;
	this->shouldRotate = false;
}

//  void WXCanvas::DrawEllipse(const Point &center, double verticalR, double horizontalRadius)
//  {
//  	canvas.DrawEllipse(center.x, center.y, verticalR * 2, horizontalRadius * 2);
//  }
//
//  void WXCanvas::DrawLine(const Point &from, const Point &to)
//  {
//  	canvas.DrawLine(from.x, from.y, to.x, to.y);
//  }

// void WXCanvas::DrawRegularPolygon(const std::vector<Point> &points)
//{
//	std::vector<wxPoint> wxPoints{};
//	wxPoints.reserve(points.size());
//	std::for_each(points.begin(), points.end(), [&wxPoints](auto &p)
//				  { wxPoints.emplace_back(wxPoint{int(p.x), int(p.y)}); });
//	canvas.DrawPolygon(points.size(), wxPoints.data());
// }

void WXCanvas::DrawRectangle(double centerX, double centerY, double width, double height, double angle)
{
	GraphicObject obj{
		{0, 0, width, height},
		wxColor(255, 0, 255, 128),
		{}};

	obj.transform.Translate(
		centerX,
		centerY);

	obj.transform.Rotate(angle);

	this->objectList.push_back(std::move(obj));

	SendRectAddedEvent();
	Refresh();
}

void WXCanvas::RemoveSelected()
{
	if (!this->objectList.empty() && draggedObj == nullptr)
	{
		this->objectList.pop_back();

		SendRectRemovedEvent();
		Refresh();
	}
}

// void WXCanvas::DrawEllipse(double centerX, double centerY, double verticalR, double horizontalR, double angle)
//{
//	GraphicObject obj{
//		{0, 0, verticalR, horizontalR},
//		*wxBLACK,
//		{}};
//
//	obj.transform.Rotate(angle);
//
//	this->objectList.push_back(std::move(obj));
//
//	SendEllipseAddedEvent();
//	Refresh();
// }

// void WXCanvas::DrawTriangle(double verticalR, double horizontalR, double centerX, double centerY, double angle)
//{
//	GraphicObject obj{
//		{0, 0, verticalR, horizontalR},
//		*wxRED,
//		{}};
//
//	obj.transform.Rotate(angle);
//
//	this->objectList.push_back(std::move(obj));
//
//	SendEllipseAddedEvent();
//	Refresh();
// }

void WXCanvas::OnPaint(wxPaintEvent &evt)
{
	// For windows
	wxAutoBufferedPaintDC dc(this);
	dc.Clear();

	wxGraphicsContext *gc = wxGraphicsContext::Create(dc);

	if (gc)
	{
		for (const auto &object : objectList)
		{
			gc->SetTransform(gc->CreateMatrix(object.transform));

			gc->SetBrush(wxBrush(object.color));
			gc->DrawRectangle(object.rect.m_x, object.rect.m_y, object.rect.m_width, object.rect.m_height);
		}

		delete gc;
	}
}

void WXCanvas::OnMouseDown(wxMouseEvent &event)
{ // clang-format off
    auto clickedObjectIter = std::find_if(objectList.rbegin(), objectList.rend(), [event](const GraphicObject &o)
                            {
                                wxPoint2DDouble clickPos = event.GetPosition();
                                auto inv = o.transform;
                                inv.Invert();
                                clickPos = inv.TransformPoint(clickPos);
                                return o.rect.Contains(clickPos); 
                            });
	// clang-format on

	if (clickedObjectIter != objectList.rend())
	{
		auto forwardIt = std::prev(clickedObjectIter.base());

		objectList.push_back(*forwardIt);
		objectList.erase(forwardIt);

		draggedObj = &(*std::prev(objectList.end()));

		lastDragOrigin = event.GetPosition();
		shouldRotate = wxGetKeyState(WXK_ALT);

		Refresh(); // for z order reversal
	}
	else
	{
		return; // TODO Unselect
	}
}

void WXCanvas::OnMouseMove(wxMouseEvent &event)
{
	if (draggedObj != nullptr)
	{
		if (shouldRotate)
		{
			double absoluteYDiff = event.GetPosition().y - lastDragOrigin.m_y;
			draggedObj->transform.Rotate(absoluteYDiff / 100.0 * M_PI);
		}
		else
		{
			auto dragVector = event.GetPosition() - lastDragOrigin;

			auto inv = draggedObj->transform;
			inv.Invert();
			dragVector = inv.TransformDistance(dragVector);

			draggedObj->transform.Translate(dragVector.m_x, dragVector.m_y);
		}

		lastDragOrigin = event.GetPosition();
		Refresh();
	}
}

void WXCanvas::OnMouseUp(wxMouseEvent &event)
{
	FinishDrag();
	FinishRotation();
}

void WXCanvas::OnMouseLeave(wxMouseEvent &event)
{
	FinishDrag();
	FinishRotation();
}

void WXCanvas::FinishDrag()
{
	draggedObj = nullptr;
}

void WXCanvas::FinishRotation()
{
	shouldRotate = false;
}

void WXCanvas::SendRectAddedEvent()
{
	wxCommandEvent event(CANVAS_RECT_ADDED, GetId());
	event.SetEventObject(this);

	ProcessWindowEvent(event);
}

void WXCanvas::SendRectRemovedEvent()
{
	wxCommandEvent event(CANVAS_RECT_REMOVED, GetId());
	event.SetEventObject(this);

	ProcessWindowEvent(event);
}

void WXCanvas::SendEllipseAddedEvent()
{
	wxCommandEvent event(CANVAS_ELLIPSE_ADDED, GetId());
	event.SetEventObject(this);
	ProcessWindowEvent(event);
}

void WXCanvas::SendEllipseRemovedEvent()
{
	wxCommandEvent event(CANVAS_ELLIPSE_REMOVED, GetId());
	event.SetEventObject(this);
	ProcessWindowEvent(event);
}

// const auto wxPINK_BRUSH = wxBrush(wxColor{255, 182, 193});
//
// decltype(auto) GetColoredBrush(Color color)
//{
//	switch (color)
//	{
//	case Color::BLACK:
//		return wxBLACK_BRUSH;
//	case Color::BLUE:
//		return wxBLUE_BRUSH;
//	case Color::GREEN:
//		return wxGREEN_BRUSH;
//	case Color::PINK:
//		return &wxPINK_BRUSH;
//	case Color::RED:
//		return wxRED_BRUSH;
//	case Color::YELLOW:
//		return wxYELLOW_BRUSH;
//	}
//	return wxBLACK_BRUSH;
// };
//
// void WXCanvas::SetColor(Color color)
//{
//	m_svgFile.SetBrush(*GetColoredBrush(color));
// }