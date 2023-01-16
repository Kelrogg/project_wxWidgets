#ifndef YOUR_PROJECT_NAME_CONTROLLER_HPP
#define YOUR_PROJECT_NAME_CONTROLLER_HPP

#include "../view/initial/InitialFrame.hpp"

class Controller
{
protected:
    wxFrame *frame;

    virtual void Create_frame();

    virtual void Create_binds();

private:
public:
    Controller();

    Controller(wxFrame *frame);

    ~Controller();

    virtual bool Toggle_view();
};

#endif // YOUR_PROJECT_NAME_CONTROLLER_HPP