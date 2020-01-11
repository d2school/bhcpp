/***************************************************************
 * Name:      HelloGUILayoutMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    zhuangyan (nanu@sina.com)
 * Created:   2015-02-24
 * Copyright: zhuangyan (www.d2school.com)
 * License:
 **************************************************************/

#include "HelloGUILayoutMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(HelloGUILayoutDialog)
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

//(*IdInit(HelloGUILayoutDialog)
const long HelloGUILayoutDialog::ID_STATICTEXT1 = wxNewId();
const long HelloGUILayoutDialog::ID_BUTTON3 = wxNewId();
const long HelloGUILayoutDialog::ID_BUTTON1 = wxNewId();
const long HelloGUILayoutDialog::ID_STATICLINE1 = wxNewId();
const long HelloGUILayoutDialog::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(HelloGUILayoutDialog,wxDialog)
    //(*EventTable(HelloGUILayoutDialog)
    //*)
END_EVENT_TABLE()

HelloGUILayoutDialog::HelloGUILayoutDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(HelloGUILayoutDialog)
    Create(parent, id, _("wxWidgets app"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
    SetClientSize(wxSize(358,118));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Welcome to wxWidgets"), wxDefaultPosition, wxSize(335,66), wxALIGN_CENTRE|wxSTATIC_BORDER, _T("ID_STATICTEXT1"));
    wxFont StaticText1Font = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    if ( !StaticText1Font.Ok() ) StaticText1Font = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    StaticText1Font.SetPointSize(20);
    StaticText1->SetFont(StaticText1Font);
    BoxSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 10);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer2->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button3 = new wxButton(this, ID_BUTTON3, _("Hello GUI !"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    BoxSizer2->Add(Button3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button1 = new wxButton(this, ID_BUTTON1, _("About"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer2->Add(Button1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxSize(2,24), wxLI_VERTICAL, _T("ID_STATICLINE1"));
    BoxSizer2->Add(StaticLine1, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    Button2 = new wxButton(this, ID_BUTTON2, _("Quit"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer2->Add(Button2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    BoxSizer1->Add(BoxSizer2, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    SetSizer(BoxSizer1);
    SetSizer(BoxSizer1);
    Layout();

    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&HelloGUILayoutDialog::OnButton3Click);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&HelloGUILayoutDialog::OnAbout);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&HelloGUILayoutDialog::OnQuit);
    //*)
}

HelloGUILayoutDialog::~HelloGUILayoutDialog()
{
    //(*Destroy(HelloGUILayoutDialog)
    //*)
}

void HelloGUILayoutDialog::OnQuit(wxCommandEvent& event)
{
    Close();
}

void HelloGUILayoutDialog::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void HelloGUILayoutDialog::OnButton3Click(wxCommandEvent& event)
{
    this->StaticText1->SetLabel(wxT("Hello wxSmith !"));
}
