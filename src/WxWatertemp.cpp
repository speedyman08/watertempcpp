#include "WxWatertemp.h"

bool WxWatertemp::OnInit() {
    wxInitAllImageHandlers();

    Menu = new wxMenu {};
    Tray = new wxTaskBarIcon {};

    Menu->Append(wxID_ANY, "Temperature, uhh", "");
    Menu->Append(wxID_ANY, "", "", wxITEM_SEPARATOR);
    Menu->Append(wxID_EXIT, "Quit");

    Menu->FindItemByPosition(0)->Enable(false);

    Tray->SetIcon(m_getIcon(), "Watertemp");
    Tray->Bind(wxEVT_MENU, [](wxCommandEvent& evt){wxTheApp->ExitMainLoop();}, wxID_EXIT);
    Tray->Bind(wxEVT_TASKBAR_RIGHT_UP, [this](wxTaskBarIconEvent& evt){Tray->PopupMenu(Menu);});
    return true;
}

wxBitmapBundle WxWatertemp::m_getIcon() {
    auto bmp {wxBitmap{"./icon.bmp", wxBITMAP_TYPE_BMP}};
    if (!bmp.IsOk()) {
        wxSafeShowMessage("watertemp","Could not load icon.bmp");
        exit(1);
    }
    return wxBitmapBundle {bmp};
}

