#include "pch.hpp"
/*
#include <wx/graphics.h>
#include <wx/dcbuffer.h>

#include "Model/Canvas/drawingcanvas.hpp"
#include "Model/Document/Elements/Shapes/Ellipse.hpp"

wxDEFINE_EVENT(CANVAS_RECT_ADDED, wxCommandEvent);
wxDEFINE_EVENT(CANVAS_RECT_REMOVED, wxCommandEvent);
wxDEFINE_EVENT(CANVAS_ELLIPSE_ADDED, wxCommandEvent);
wxDEFINE_EVENT(CANVAS_ELLIPSE_REMOVED, wxCommandEvent);
wxDEFINE_EVENT(CANVAS_TRIANGLE_ADDED, wxCommandEvent);
wxDEFINE_EVENT(CANVAS_TRIANGLE_REMOVED, wxCommandEvent);

DrawingCanvas::DrawingCanvas(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size) : wxWindow(parent, id, pos, size)
{
    this->SetBackgroundStyle(wxBG_STYLE_PAINT); // needed for windows

    this->Bind(wxEVT_PAINT, &DrawingCanvas::OnPaint, this);
    this->Bind(wxEVT_LEFT_DOWN, &DrawingCanvas::OnMouseDown, this);
    this->Bind(wxEVT_MOTION, &DrawingCanvas::OnMouseMove, this);
    this->Bind(wxEVT_LEFT_UP, &DrawingCanvas::OnMouseUp, this);
    this->Bind(wxEVT_LEAVE_WINDOW, &DrawingCanvas::OnMouseLeave, this);

    // DELETE
    AddRect(this->FromDIP(100), this->FromDIP(80), this->FromDIP(210), this->FromDIP(140), 0, *wxRED);
    AddRect(this->FromDIP(130), this->FromDIP(110), this->FromDIP(280), this->FromDIP(210), M_PI / 3.0, *wxBLUE);
    AddRect(this->FromDIP(110), this->FromDIP(110), this->FromDIP(300), this->FromDIP(120), -M_PI / 4.0, wxColor(255, 0, 255, 128));

    this->draggedObj = nullptr;
    this->shouldRotate = false;
}

void DrawingCanvas::AddRect(double width, double height, double topLeftX, double topLeftY, double angle, wxColor color)
{
    GraphicObject obj{
        {0, 0, width, height},
        color,
        {}};

    obj.transform.Translate(
        topLeftX,
        topLeftY);

    obj.transform.Rotate(angle);

    this->objectList.push_back(std::move(obj));

    SendRectAddedEvent();
    Refresh();
}

void DrawingCanvas::RemoveSelected()
{
    if (!this->objectList.empty() && draggedObj == nullptr)
    {
        this->objectList.pop_back();

        SendRectRemovedEvent();
        Refresh();
    }
}

void DrawingCanvas::AddEllipse(double verticalR, double horizontalR, double centerX, double centerY, double angle, wxColor color)
{
    GraphicObject obj{
        {0, 0, verticalR, horizontalR},
        color,
        {}};

    obj.transform.Rotate(angle);

    this->objectList.push_back(std::move(obj));

    SendEllipseAddedEvent();
    Refresh();
}

void DrawingCanvas::AddTriangle(double verticalR, double horizontalR, double centerX, double centerY, double angle, wxColor color)
{
    GraphicObject obj{
        {0, 0, verticalR, horizontalR},
        color,
        {}};

    obj.transform.Rotate(angle);

    this->objectList.push_back(std::move(obj));

    SendEllipseAddedEvent();
    Refresh();
}

void DrawingCanvas::OnPaint(wxPaintEvent &evt)
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

void DrawingCanvas::OnMouseDown(wxMouseEvent &event)
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

void DrawingCanvas::OnMouseMove(wxMouseEvent &event)
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

void DrawingCanvas::OnMouseUp(wxMouseEvent &event)
{
    FinishDrag();
    FinishRotation();
}

void DrawingCanvas::OnMouseLeave(wxMouseEvent &event)
{
    FinishDrag();
    FinishRotation();
}

void DrawingCanvas::FinishDrag()
{
    draggedObj = nullptr;
}

void DrawingCanvas::FinishRotation()
{
    shouldRotate = false;
}

void DrawingCanvas::SendRectAddedEvent()
{
    wxCommandEvent event(CANVAS_RECT_ADDED, GetId());
    event.SetEventObject(this);

    ProcessWindowEvent(event);
}

void DrawingCanvas::SendRectRemovedEvent()
{
    wxCommandEvent event(CANVAS_RECT_REMOVED, GetId());
    event.SetEventObject(this);

    ProcessWindowEvent(event);
}

void DrawingCanvas::SendEllipseAddedEvent()
{
    wxCommandEvent event(CANVAS_ELLIPSE_ADDED, GetId());
    event.SetEventObject(this);
    ProcessWindowEvent(event);
}

void DrawingCanvas::SendEllipseRemovedEvent()
{
    wxCommandEvent event(CANVAS_ELLIPSE_REMOVED, GetId());
    event.SetEventObject(this);
    ProcessWindowEvent(event);
} */