/***************************************************************
 * Name:      HelloInternetMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    NanYu (nanyu@sina.com)
 * Created:   2008-10-26
 * Copyright: NanYu (www.d2school.com)
 * License:
 **************************************************************/

#include "HelloInternetMain.h"
#include <wx/msgdlg.h>

#include <wx/protocol/http.h>
#include <wx/mstream.h>

//(*InternalHeaders(HelloInternetDialog)
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

//(*IdInit(HelloInternetDialog)
const long HelloInternetDialog::ID_STATICTEXT2 = wxNewId();
const long HelloInternetDialog::ID_TEXTCTRL1 = wxNewId();
const long HelloInternetDialog::ID_BUTTON3 = wxNewId();
const long HelloInternetDialog::ID_STATICTEXT1 = wxNewId();
const long HelloInternetDialog::ID_BUTTON1 = wxNewId();
const long HelloInternetDialog::ID_STATICLINE1 = wxNewId();
const long HelloInternetDialog::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(HelloInternetDialog,wxDialog)
    //(*EventTable(HelloInternetDialog)
    //*)
END_EVENT_TABLE()

HelloInternetDialog::HelloInternetDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(HelloInternetDialog)
    wxBoxSizer* BoxSizer3;

    Create(parent, wxID_ANY, _("Hello Internet"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(481,112));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer3 = new wxBoxSizer(wxVERTICAL);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("请输入您的姓名："), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    BoxSizer3->Add(StaticText2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("丁小明"), wxDefaultPosition, wxSize(117,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    BoxSizer3->Add(TextCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button3 = new wxButton(this, ID_BUTTON3, _("问候(&W)"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    BoxSizer3->Add(Button3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Welcome to\nwxWidgets"), wxDefaultPosition, wxSize(269,67), 0, _T("ID_STATICTEXT1"));
    wxFont StaticText1Font(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("宋体"),wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
    BoxSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 10);
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    Button1 = new wxButton(this, ID_BUTTON1, _("关于"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    BoxSizer2->Add(StaticLine1, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    Button2 = new wxButton(this, ID_BUTTON2, _("退出"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer2->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    BoxSizer1->Add(BoxSizer2, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    SetSizer(BoxSizer1);
    SetSizer(BoxSizer1);
    Layout();

    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&HelloInternetDialog::OnButton3Click);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&HelloInternetDialog::OnAbout);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&HelloInternetDialog::OnQuit);
    //*)
}

HelloInternetDialog::~HelloInternetDialog()
{
    //(*Destroy(HelloInternetDialog)
    //*)
}

void HelloInternetDialog::OnQuit(wxCommandEvent& event)
{
    Close();
}

void HelloInternetDialog::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

wxString FromGB2312(wxStreamBuffer const * buf)
{
    return wxString((char const *)buf->GetBufferStart()
        , wxCSConv(wxT("gb2312"))
        , buf->GetBufferSize());
}

void HelloInternetDialog::OnButton3Click(wxCommandEvent& event)
{
    wxHTTP http;

    //尝试连接网站：
    if (!http.Connect(_T("www.d2school.com")))
    {
        wxMessageBox(_T("连接不上第二学堂！"));
        return;
    }

    //拼装出URL：/hello.php?name=丁小明
    wxString url = _T("/hello.php?name=");
    url += this->TextCtrl1->GetValue();

    //一个HTTP的“输入流”，是指它的从网站返回的内容。
    wxInputStream* in = http.GetInputStream(url);

    if (!in)
    {
        wxMessageBox(_T("无法获得指定网址的输入流！"));
        return;
    }

    //将该HTTP返回的内容读入到一个“内存流”中
    wxMemoryOutputStream mem;
    in->Read(mem);

    //读完以后，输入流就可以释放了
    delete in;

    //将内存流中的内容，转换为UNICODE编码
    wxString result = FromGB2312(mem.GetOutputStreamBuffer());

    //显示
    StaticText1->SetLabel(result);
}
