#include "pch.hpp"

#include "View/View.hpp"

// clang-format off
View::View(const wxString &title, const wxPoint &pos, const wxSize &size, Model &&model)
    : wxFrame(NULL, wxID_ANY, title, pos, size)
    , m_model(std::forward<Model>(model))
    , m_controller(std::forward<Model>(model))
// clang-format on
{
    wxSizer *sizer = new wxBoxSizer(wxVERTICAL);

    CreateMenuBar();
    wxPanel *drawingPaneWithButtons = new wxPanel(this);
    //  auto buttonPanel = CreateMenuBar(drawingPaneWithButtons);
    //  Controller
    canvas = new WXCanvas(drawingPaneWithButtons, wxID_ANY, wxDefaultPosition, wxDefaultSize);
    canvas->Bind(CANVAS_RECT_ADDED, &View::OnRectAdded, this);
    canvas->Bind(CANVAS_RECT_REMOVED, &View::OnRectRemoved, this);
    canvas->Bind(CANVAS_ELLIPSE_ADDED, &View::OnRectRemoved, this);
    canvas->Bind(CANVAS_ELLIPSE_REMOVED, &View::OnRectRemoved, this);
    canvas->Bind(CANVAS_TRIANGLE_ADDED, &View::OnRectRemoved, this);
    canvas->Bind(CANVAS_TRIANGLE_REMOVED, &View::OnRectRemoved, this);

    // sizer->Add(buttonPanel, 0, wxEXPAND | wxALL, 0);
    sizer->Add(canvas, 1, wxEXPAND | wxALL, 0);

    drawingPaneWithButtons->SetSizerAndFit(sizer);

    CreateStatusBar(1);
    SetStatusText("Ready", 0);
}

void View::OnAddRectangleButtonClick(wxCommandEvent &event)
{
    std::uniform_int_distribution colorDistrib(0, 0xFFFFFF);

    canvas->DrawRectangle(this->FromDIP(50), this->FromDIP(50), canvas->GetSize().GetWidth() / 2, canvas->GetSize().GetHeight() / 2,
                          0.0);
}

void View::OnAddTriangleButtonClick(wxCommandEvent &event)
{
    std::uniform_int_distribution colorDistrib(0, 0xFFFFFF);

    canvas->DrawRectangle(this->FromDIP(50), this->FromDIP(50), canvas->GetSize().GetWidth() / 2, canvas->GetSize().GetHeight() / 2,
                          0.0);
}

void View::OnAddEllipseButtonClick(wxCommandEvent &event)
{
    std::uniform_int_distribution colorDistrib(0, 0xFFFFFF);

    canvas->DrawRectangle(this->FromDIP(50), this->FromDIP(50), canvas->GetSize().GetWidth() / 2, canvas->GetSize().GetHeight() / 2,
                          0.0);
}

void View::OnRemoveButtonClick(wxCommandEvent &event)
{
    canvas->RemoveSelected();
}

void View::OnRectAdded(wxCommandEvent &event)
{
    SetStatusText("Rect " + event.GetString() + " added!", 0);
}

void View::OnRectRemoved(wxCommandEvent &event)
{
    SetStatusText("Rect " + event.GetString() + " removed!", 0);
}

void View::CreateMenuBar()
{
    wxMenuBar *menuBar = new wxMenuBar();

    wxMenu *fileMenu = new wxMenu();
    fileMenu->Append(wxID_NEW);
    fileMenu->Append(wxID_OPEN);
    fileMenu->AppendSeparator();
    fileMenu->Append(wxID_SAVE);
    fileMenu->Append(wxID_SAVEAS);

    wxMenu *editMenu = new wxMenu();

    editMenu->Append(wxID_UNDO);
    editMenu->Append(wxID_REDO);
    editMenu->AppendSeparator();
    editMenu->Append(wxID_CUT);
    editMenu->Append(wxID_COPY);
    editMenu->Append(wxID_PASTE);

    wxMenu *customMenu = new wxMenu();

    customMenu->AppendSeparator();
    this->Bind(wxEVT_MENU, &View::OnAddTriangleButtonClick, this,
               customMenu->Append(wxID_ANY, "Triangle")->GetId());
    this->Bind(wxEVT_MENU, &View::OnAddRectangleButtonClick, this,
               customMenu->Append(wxID_ANY, "Rectangle")->GetId());
    this->Bind(wxEVT_MENU, &View::OnAddEllipseButtonClick, this,
               customMenu->Append(wxID_ANY, "Ellipse")->GetId());
    customMenu->AppendSeparator();

    wxMenu *customMenuOptionsSubmenu = new wxMenu();

    menuBar->Append(fileMenu, "&File");
    menuBar->Append(editMenu, "&Edit");
    menuBar->Append(customMenu, "&Insert");

    SetMenuBar(menuBar);
}