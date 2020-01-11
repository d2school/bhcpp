/***************************************************************
 * Name:      ProjectSettingDemoMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    nanyu (nanyu@sina.com.cn)
 * Created:   2009-12-12
 * Copyright: nanyu (www.d2school.com)
 * License:
 **************************************************************/

#include "ProjectSettingDemoMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(ProjectSettingDemoDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(ProjectSettingDemoDialog)
//*)

BEGIN_EVENT_TABLE(ProjectSettingDemoDialog,wxDialog)
    //(*EventTable(ProjectSettingDemoDialog)
    //*)
END_EVENT_TABLE()

ProjectSettingDemoDialog::ProjectSettingDemoDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(ProjectSettingDemoDialog)
    Create(parent, id, _("wxWidgets app"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER, _T("id"));
    SetClientSize(wxSize(345,214));

    Connect(wxEVT_SIZE,(wxObjectEventFunction)&ProjectSettingDemoDialog::OnResize);
    //*)
}

ProjectSettingDemoDialog::~ProjectSettingDemoDialog()
{
    //(*Destroy(ProjectSettingDemoDialog)
    //*)
}

void ProjectSettingDemoDialog::OnQuit(wxCommandEvent& event)
{
    Close();
}

void ProjectSettingDemoDialog::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void ProjectSettingDemoDialog::OnResize(wxSizeEvent& event)
{
}
