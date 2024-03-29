#pragma once
#include "pch.hpp"

#include <wx/wx.h>

// #include "Model/Shapes/IShape.hpp"
#include "Model/Document/Elements/IElement.hpp"
#include "graphicobject.hpp"

wxDECLARE_EVENT(CANVAS_RECT_ADDED, wxCommandEvent);
wxDECLARE_EVENT(CANVAS_RECT_REMOVED, wxCommandEvent);
wxDECLARE_EVENT(CANVAS_ELLIPSE_ADDED, wxCommandEvent);
wxDECLARE_EVENT(CANVAS_ELLIPSE_REMOVED, wxCommandEvent);
wxDECLARE_EVENT(CANVAS_TRIANGLE_ADDED, wxCommandEvent);
wxDECLARE_EVENT(CANVAS_TRIANGLE_REMOVED, wxCommandEvent);

class DrawingCanvas : public wxWindow
{
public:
    DrawingCanvas(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size);
    virtual ~DrawingCanvas() {}

    void AddRect(double width, double height, double centerX, double centerY, double angle, wxColor color);
    void AddEllipse(double verticalR, double horizontalR, double centerX, double centerY, double angle, wxColor color);
    void AddTriangle(double verticalR, double horizontalR, double centerX, double centerY, double angle, wxColor color);
    void RemoveSelected();

    int GetObjectCount() { return objectList.size(); }

private:
    void OnPaint(wxPaintEvent &evt);
    void OnMouseDown(wxMouseEvent &event);
    void OnMouseMove(wxMouseEvent &event);
    void OnMouseUp(wxMouseEvent &event);
    void OnMouseLeave(wxMouseEvent &event);

    void FinishDrag();
    void FinishRotation();

    void SendRectAddedEvent();
    void SendRectRemovedEvent();
    void SendEllipseAddedEvent();
    void SendEllipseRemovedEvent();

    std::list<GraphicObject> objectList;

    GraphicObject *draggedObj;
    bool shouldRotate;

    wxPoint2DDouble lastDragOrigin;
};