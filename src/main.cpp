#include "pch.hpp"

#include <wx/wx.h>
#include <wx/listbook.h>

#include "Model/Canvas/drawingcanvas.hpp"

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};
wxIMPLEMENT_APP(MyApp);

class MyFrame : public wxFrame
{
public:
    MyFrame(const wxString &title, const wxPoint &pos, const wxSize &size);

private:
    void OnAddRectangleButtonClick(wxCommandEvent &event);
    void OnAddTriangleButtonClick(wxCommandEvent &event);
    void OnAddEllipseButtonClick(wxCommandEvent &event);
    void OnRemoveButtonClick(wxCommandEvent &event);

    void OnRectAdded(wxCommandEvent &event);
    void OnRectRemoved(wxCommandEvent &event);

    wxPanel *createButtonPanel(wxWindow *parent);

    DrawingCanvas *canvas;

    std::mt19937 randomGen;
    // model, controller
};

bool MyApp::OnInit()
{
    // MyFrame *frame = new MyFrame("Hello World", wxPoint(50, 50), wxDefaultSize);
    MyFrame *frame = new MyFrame("Hello Patterns $) ;)", wxPoint(100, 100), wxDefaultSize);
    frame->Show(true);
    return true;
}

MyFrame::MyFrame(const wxString &title, const wxPoint &pos, const wxSize &size)
    : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    wxSizer *sizer = new wxBoxSizer(wxVERTICAL);

    wxPanel *drawingPaneWithButtons = new wxPanel(this);
    auto buttonPanel = createButtonPanel(drawingPaneWithButtons);
    canvas = new DrawingCanvas(drawingPaneWithButtons, wxID_ANY, wxDefaultPosition, wxDefaultSize);
    canvas->Bind(CANVAS_RECT_ADDED, &MyFrame::OnRectAdded, this);
    canvas->Bind(CANVAS_RECT_REMOVED, &MyFrame::OnRectRemoved, this);

    sizer->Add(buttonPanel, 0, wxEXPAND | wxALL, 0);
    sizer->Add(canvas, 1, wxEXPAND | wxALL, 0);

    drawingPaneWithButtons->SetSizerAndFit(sizer);

    CreateStatusBar(1);
    SetStatusText("Ready", 0);
}

void MyFrame::OnAddRectangleButtonClick(wxCommandEvent &event)
{
    std::uniform_int_distribution sizeDistrib(this->FromDIP(50), this->FromDIP(100));
    std::uniform_int_distribution xDistrib(0, canvas->GetSize().GetWidth());
    std::uniform_int_distribution yDistrib(0, canvas->GetSize().GetHeight());
    std::uniform_real_distribution angleDistrib(0.0, M_PI * 2.0);

    std::uniform_int_distribution colorDistrib(0, 0xFFFFFF);

    canvas->addRect(sizeDistrib(randomGen), sizeDistrib(randomGen), xDistrib(randomGen), yDistrib(randomGen),
                    angleDistrib(randomGen), wxColour(colorDistrib(randomGen)), "");
}

void MyFrame::OnAddTriangleButtonClick(wxCommandEvent &event)
{
    std::uniform_int_distribution sizeDistrib(this->FromDIP(50), this->FromDIP(100));
    std::uniform_int_distribution xDistrib(0, canvas->GetSize().GetWidth());
    std::uniform_int_distribution yDistrib(0, canvas->GetSize().GetHeight());
    std::uniform_real_distribution angleDistrib(0.0, M_PI * 2.0);

    std::uniform_int_distribution colorDistrib(0, 0xFFFFFF);

    canvas->addRect(sizeDistrib(randomGen), sizeDistrib(randomGen), xDistrib(randomGen), yDistrib(randomGen),
                    angleDistrib(randomGen), wxColour(colorDistrib(randomGen)), "");
}

void MyFrame::OnAddEllipseButtonClick(wxCommandEvent &event)
{
    std::uniform_int_distribution sizeDistrib(this->FromDIP(50), this->FromDIP(100));
    std::uniform_int_distribution xDistrib(0, canvas->GetSize().GetWidth());
    std::uniform_int_distribution yDistrib(0, canvas->GetSize().GetHeight());
    std::uniform_real_distribution angleDistrib(0.0, M_PI * 2.0);

    std::uniform_int_distribution colorDistrib(0, 0xFFFFFF);

    canvas->addRect(sizeDistrib(randomGen), sizeDistrib(randomGen), xDistrib(randomGen), yDistrib(randomGen),
                    angleDistrib(randomGen), wxColour(colorDistrib(randomGen)), "");
}

void MyFrame::OnRemoveButtonClick(wxCommandEvent &event)
{
    canvas->removeTopRect();
}

void MyFrame::OnRectAdded(wxCommandEvent &event)
{
    SetStatusText("Rect named " + event.GetString() + " added!", 0);
}

void MyFrame::OnRectRemoved(wxCommandEvent &event)
{
    SetStatusText("Rect named " + event.GetString() + " REMOVED!", 0);
}

wxPanel *MyFrame::createButtonPanel(wxWindow *parent)
{
    wxPanel *panel = new wxPanel(parent);
    wxButton *addRectButton = new wxButton(panel, wxID_ANY, "Add Rect");
    wxButton *addEllipseButton = new wxButton(panel, wxID_ANY, "Add Ellipse");
    wxButton *addTriangleButton = new wxButton(panel, wxID_ANY, "Add Triangle");
    wxButton *removeLastButton = new wxButton(panel, wxID_ANY, "Remove Top");

    wxSizer *sizer = new wxBoxSizer(wxHORIZONTAL);
    sizer->Add(addRectButton, 0, wxEXPAND | wxALL, 3);
    sizer->Add(addEllipseButton, 0, wxEXPAND | wxALL, 3);
    sizer->Add(addTriangleButton, 0, wxEXPAND | wxALL, 3);
    sizer->Add(removeLastButton, 0, wxEXPAND | wxALL, 3);

    panel->SetSizer(sizer);

    addRectButton->Bind(wxEVT_BUTTON, &MyFrame::OnAddRectangleButtonClick, this);
    removeLastButton->Bind(wxEVT_BUTTON, &MyFrame::OnRemoveButtonClick, this);

    return panel;
}