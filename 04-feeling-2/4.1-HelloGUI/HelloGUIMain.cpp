/***************************************************************
 * Name:      HelloGUIMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    NanYU (nanyu@sina.com)
 * Created:   2008-10-26
 * Copyright: NanYU (www.d2school.com)
 * License:
 **************************************************************/

#include "HelloGUIMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(HelloGUIDialog)
#include <wx/settings.h>
#include <wx/font.h>
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

//(*IdInit(HelloGUIDialog)
const long HelloGUIDialog::ID_STATICTEXT_WELCOME = wxNewId();
const long HelloGUIDialog::ID_BUTTON_ABOUT = wxNewId();
const long HelloGUIDialog::ID_STATICLINE1 = wxNewId();
const long HelloGUIDialog::ID_BUTTON_QUIT = wxNewId();
//*)

BEGIN_EVENT_TABLE(HelloGUIDialog,wxDialog)
    //(*EventTable(HelloGUIDialog)
    //*)
END_EVENT_TABLE()

HelloGUIDialog::HelloGUIDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(HelloGUIDialog)
    Create(parent, id, _("Hello GUI"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT_WELCOME, _("欢迎使用\nwxWidgets!"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT_WELCOME"));
    wxFont StaticText1Font = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    if ( !StaticText1Font.Ok() ) StaticText1Font = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    StaticText1Font.SetPointSize(20);
    StaticText1->SetFont(StaticText1Font);
    BoxSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 10);
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    ButtonAbout = new wxButton(this, ID_BUTTON_ABOUT, _("关于"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_ABOUT"));
    BoxSizer2->Add(ButtonAbout, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    BoxSizer2->Add(StaticLine1, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    ButtonQuit = new wxButton(this, ID_BUTTON_QUIT, _("退出"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_QUIT"));
    BoxSizer2->Add(ButtonQuit, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    BoxSizer1->Add(BoxSizer2, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    SetSizer(BoxSizer1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_BUTTON_ABOUT,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&HelloGUIDialog::OnAbout);
    Connect(ID_BUTTON_QUIT,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&HelloGUIDialog::OnQuit);
    //*)
}

HelloGUIDialog::~HelloGUIDialog()
{
    //(*Destroy(HelloGUIDialog)
    //*)
}

void HelloGUIDialog::OnQuit(wxCommandEvent& event)
{
    Close();
}

void HelloGUIDialog::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}
