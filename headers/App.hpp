#ifndef WXWIDGETSHELLOWORLD_APP_Hpp
#define WXWIDGETSHELLOWORLD_APP_Hpp

// wxWidgets "Hello World" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class App : public wxApp
{
    virtual bool OnInit();
};

#endif // WXWIDGETSHELLOWORLD_APP_Hpp