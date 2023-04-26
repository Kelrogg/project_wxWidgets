#ifndef VIEW_HPP
#define VIEW_HPP

#include <wx/wx.h>

#include "Controller/Controller.hpp"
#include "Model/Canvas/WXCanvas.hpp"

class View : public wxFrame
{
public:
    View(const wxString &title, const wxPoint &pos, const wxSize &size, Model &&model);

private:
    void OnAddRectangleButtonClick(wxCommandEvent &event);
    void OnAddTriangleButtonClick(wxCommandEvent &event);
    void OnAddEllipseButtonClick(wxCommandEvent &event);
    void OnRemoveButtonClick(wxCommandEvent &event);

    void OnRectAdded(wxCommandEvent &event);
    void OnRectRemoved(wxCommandEvent &event);

    void CreateMenuBar();

    WXCanvas *canvas;

    Model m_model;
    Controller m_controller;
    std::mt19937 randomGen;
};

#endif