#include "pch.hpp"

#include <wx/wx.h>
#include <wx/listbook.h>

#include "Model/Canvas/drawingcanvas.hpp"

#include "Controller/Controller.hpp"
#include "View/View.hpp"
#include "Model/Model.hpp"

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    Model model;
    Controller controller(std::move(model));
    View *view = new View("Vulkan", wxPoint(100, 100), wxDefaultSize, std::move(model));

    view->Show(true);
    return true;
}