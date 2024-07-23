/***************************************************************
 * Name:      HelloMyFrameMain.cpp
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

#include "HelloMyFrameMain.h"

#include <map>

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

BEGIN_EVENT_TABLE(HelloMyFrameFrame, wxFrame)
    EVT_CLOSE(HelloMyFrameFrame::OnClose)

    EVT_MOTION(HelloMyFrameFrame::OnMotion)
    EVT_PAINT(HelloMyFrameFrame::OnPaint)

    EVT_MENU(idMenuQuit, HelloMyFrameFrame::OnQuit)
    EVT_MENU(idMenuAbout, HelloMyFrameFrame::OnAbout)
    EVT_MENU(idMenueAboutAuthor, HelloMyFrameFrame::OnAboutAuthor)

    EVT_MENU(idMenuBlueText, HelloMyFrameFrame::OnTextColorSelected)
    EVT_MENU(idMenuRedText, HelloMyFrameFrame::OnTextColorSelected)
    EVT_MENU(idMenuGreenText, HelloMyFrameFrame::OnTextColorSelected)

END_EVENT_TABLE()

HelloMyFrameFrame::HelloMyFrameFrame(wxFrame *frame, const wxString& title)
    : wxFrame(frame, -1, title)
{
#if wxUSE_MENUS && 1
    // create a menu bar
    wxMenuBar* mbar = new wxMenuBar();
    wxMenu* fileMenu = new wxMenu(_T(""));
    fileMenu->Append(idMenuQuit, _("&Quit\tAlt-F4"), _("Quit the application"));
    mbar->Append(fileMenu, _("&File"));

    wxMenu* optionsMenu = new wxMenu(_T(""));
    mbar->Append(optionsMenu, _("&Options"));
    optionsMenu->AppendCheckItem(idMenuShowMotionInfo, _("&Show motion info"), _("Show motion info or no"));

//    optionsMenu->AppendSeparator();

    optionsMenu->AppendRadioItem(idMenuBlueText, _("&Blue text"), _("Set text blue"));
    optionsMenu->AppendRadioItem(idMenuRedText, _("&Red text"), _("Set text red"));
    optionsMenu->AppendRadioItem(idMenuGreenText, _("&Green text"), _("Set text green"));

 //   optionsMenu->AppendSeparator();

  //  optionsMenu->AppendRadioItem(idMenuBlueText + 100, _("&Big text"), _("Set big blue"));
  //  optionsMenu->AppendRadioItem(idMenuRedText + 101, _("&Small text"), _("Set small re"));

    wxMenu* helpMenu = new wxMenu(_T(""));
    helpMenu->Append(idMenuAbout, _("&About\tF1"), _("Show info about this application"));
    helpMenu->Append(idMenueAboutAuthor, _("About Auth&or"), _("Show info about this application's author"));

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


HelloMyFrameFrame::~HelloMyFrameFrame()
{
}

void HelloMyFrameFrame::OnClose(wxCloseEvent &event)
{
    Destroy();
}

void HelloMyFrameFrame::OnQuit(wxCommandEvent &event)
{
    Destroy();
}

void HelloMyFrameFrame::OnAbout(wxCommandEvent &event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void HelloMyFrameFrame::OnAboutAuthor(wxCommandEvent& event)
{
    wxString msg = wxT("关于作者南郁：帅气、智慧、没钱。");
    wxMessageBox(msg, _("About author"));
}

void HelloMyFrameFrame::OnMotion(wxMouseEvent& event)
{
    xPos = event.GetPosition().x;
    yPos = event.GetPosition().y;

    this->Refresh(); // 主动刷新窗口内容
}

void HelloMyFrameFrame::OnTextColorSelected(wxCommandEvent& event)
{
    this->selectedColorMenuItemId = event.GetId();
}

void HelloMyFrameFrame::OnPaint(wxPaintEvent& event)
{
    bool showMotionInfo = this->GetMenuBar()->IsChecked(idMenuShowMotionInfo);

    wxString txt;

    if (showMotionInfo)
    {
        txt << wxT("鼠标坐标：") << xPos << wxT(" - ") << yPos;
    }
    else
    {
        txt = wxT("你可以选中\"Show motion info 来显示鼠标信息\"");
    }

    wxPaintDC dc (this);

    static std::map<int, wxColor const*> colors =
    {
        {idMenuBlueText, wxBLUE},
        {idMenuRedText, wxRED},
        {idMenuGreenText, wxGREEN}
    };

    if (wxColor const* txtColor = colors[this->selectedColorMenuItemId]; txtColor)
    {
        dc.SetTextForeground(*txtColor);
    }

    wxPoint pos (xPos + 10, yPos + 10);
    dc.DrawText(txt, pos);
}

