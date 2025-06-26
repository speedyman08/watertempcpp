#ifndef WXWATERTEMP_H
#define WXWATERTEMP_H

#include "wx/taskbar.h"
#include "wx/menu.h"
#include "wx/app.h"

class WxWatertemp : public wxApp {
    wxMenu* Menu;
    wxTaskBarIcon* Tray;
    static wxBitmapBundle m_getIcon();
public:
    bool OnInit() override;
};

#endif //WXWATERTEMP_H
