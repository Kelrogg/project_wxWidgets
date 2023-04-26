#ifndef CANVAS_WX_CANVAS_HPP
#define CANVAS_WX_CANVAS_HPP

// #include "/usr/local/lib/wx/include/gtk3-unicode-3.3/wx/setup.h"
#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "wx/dcsvg.h"
#include "wx/notebook.h"

#include "Model/Canvas/ICanvas.hpp"
#include "graphicobject.hpp"

wxDECLARE_EVENT(CANVAS_RECT_ADDED, wxCommandEvent);
wxDECLARE_EVENT(CANVAS_RECT_REMOVED, wxCommandEvent);
wxDECLARE_EVENT(CANVAS_ELLIPSE_ADDED, wxCommandEvent);
wxDECLARE_EVENT(CANVAS_ELLIPSE_REMOVED, wxCommandEvent);
wxDECLARE_EVENT(CANVAS_TRIANGLE_ADDED, wxCommandEvent);
wxDECLARE_EVENT(CANVAS_TRIANGLE_REMOVED, wxCommandEvent);

class WXCanvas : public wxWindow, public ICanvas
{
public:
    WXCanvas(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size);
    // virtual ~WXCanvas() {}

    // void DrawLine(double fromX, double fromY, double toX, double toY) final;
    void DrawRectangle(double centerX, double centerY, double width, double height, double angle) final;
    // void DrawEllipse(double centerX, double centerY, double verticalR, double horizontalR, double angle) final;
    // void DrawRegularPolygon(const std::vector<Point> &points) final;
    //  void SetColor(Color color) final;
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

#endif
