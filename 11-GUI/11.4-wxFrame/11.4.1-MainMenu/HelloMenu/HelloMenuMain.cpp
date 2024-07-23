/***************************************************************
 * Name:      HelloMenuMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    d2school (nanyu@d2school.com)
 * Created:   2024-04-11
 * Copyright: d2school (www.d2school)
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "HelloMenuMain.h"

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
#elif defined(__WXMAC__)
        wxbuild << _T("-Mac");
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

BEGIN_EVENT_TABLE(HelloMenuFrame, wxFrame)
    EVT_CLOSE(HelloMenuFrame::OnClose)

    EVT_PAINT(HelloMenuFrame::OnPaint)
    EVT_MOTION(HelloMenuFrame::OnMontion)

    EVT_MENU(idMenuQuit, HelloMenuFrame::OnQuit)
    EVT_MENU(idMenuAbout, HelloMenuFrame::OnAbout)
    EVT_MENU(idMenuAboutAuthor, HelloMenuFrame::OnAboutAuthor)
    EVT_MENU(idMenuBlueText, HelloMenuFrame::OnTextColorSelected)
    EVT_MENU(idMenuRedText, HelloMenuFrame::OnTextColorSelected)

END_EVENT_TABLE()

HelloMenuFrame::HelloMenuFrame(wxFrame *frame, const wxString& title)
    : wxFrame(frame, -1, title)
{
#if wxUSE_MENUS && 1
    // create a menu bar
    wxMenuBar* mbar = new wxMenuBar();
    wxMenu* fileMenu = new wxMenu(_T(""));
    fileMenu->Append(idMenuQuit, _("&Quit\tAlt-F4"), _("Quit the application"));
    mbar->Append(fileMenu, _("&File"));

    wxMenu* optionsMenu = new wxMenu(_T(""));
    optionsMenu->AppendCheckItem(idMenuShowMotionInfo, _("&Show motion info"), _("Show motion info or no"));
    mbar->Append(optionsMenu, _("&Options"));

    optionsMenu->AppendSeparator();

    optionsMenu->AppendRadioItem(idMenuBlueText, _("&Blue text"), _("Set text blue"));
    optionsMenu->AppendRadioItem(idMenuRedText, _("&Red text"), _("Set text red"));

    optionsMenu->AppendSeparator();

    optionsMenu->AppendRadioItem(idMenuBlueText+99, _("&Big text"), _("Set text big"));
    optionsMenu->AppendRadioItem(idMenuRedText+100, _("&Small text"), _("Set text small"));

    wxMenu* helpMenu = new wxMenu(_T(""));
    helpMenu->Append(idMenuAbout, _("&About\tF1"), _("Show info about this application"));
    helpMenu->Append(idMenuAboutAuthor, _("About autho&r"), _("Show info about author")); // 添加菜单项
    mbar->Append(helpMenu, _("&Help"));

    SetMenuBar(mbar);
#endif // wxUSE_MENUS

#if wxUSE_STATUSBAR
    // create a status bar with some information about the used wxWidgets version
    CreateStatusBar(2);
    SetStatusText(_("Hello Code::Blocks user!"),0);
    SetStatusText(wxbuildinfo(short_f), 1);
#endif // wxUSE_STATUSBAR

}


HelloMenuFrame::~HelloMenuFrame()
{
}

void HelloMenuFrame::OnClose(wxCloseEvent &event)
{
    Destroy();
}

void HelloMenuFrame::OnQuit(wxCommandEvent &event)
{
    Destroy();
}

void HelloMenuFrame::OnAbout(wxCommandEvent &event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void HelloMenuFrame::OnAboutAuthor(wxCommandEvent& event)
{
    wxString msg = wxT("关于作者南郁：帅气、智慧、没钱。");
    wxMessageBox(msg, _("About author")); // 弹出消息框，第2入参是标题
}

void HelloMenuFrame::OnMontion(wxMouseEvent& event)
{
    xPos = event.GetPosition().x;
    yPos = event.GetPosition().y;

    this->Refresh();
}

void HelloMenuFrame::OnPaint(wxPaintEvent& event)
{
    bool showMotionInfo = this->GetMenuBar()->IsChecked(idMenuShowMotionInfo);

    wxString txt;
    wxPaintDC dc(this);

    wxColour const* txtColor = (selectedColorId == idMenuBlueText)? wxBLUE : wxRED;
    dc.SetTextForeground(*txtColor);

    if (showMotionInfo)
    {
        txt << wxT("鼠标坐标：") << xPos << wxT(" - ") << yPos;
    }
    else
    {
        txt = wxT("你可以选中\"Show motion info\" 来显示鼠标位置信息");
    }

    wxPoint pos (xPos + 10, yPos + 10);
    dc.DrawText(txt, pos);
}

void HelloMenuFrame::OnTextColorSelected(wxCommandEvent& event)
{
    selectedColorId = event.GetId();
}
