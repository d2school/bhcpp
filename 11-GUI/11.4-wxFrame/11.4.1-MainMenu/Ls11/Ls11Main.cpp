/***************************************************************
 * Name:      Ls11Main.cpp
 * Purpose:   Code for Application Frame
 * Author:    d2school (nanyu@d2school.com)
 * Created:   2024-04-14
 * Copyright: d2school (www.d2school)
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "Ls11Main.h"
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

BEGIN_EVENT_TABLE(Ls11Frame, wxFrame)
    EVT_CLOSE(Ls11Frame::OnClose)

    // 绑定鼠标移动事件和响应函数
    EVT_MOTION(Ls11Frame::OnMotion)
    // 绑定窗口绘图事件和响应函数
    EVT_PAINT(Ls11Frame::OnPaint)

    EVT_MENU(idMenuQuit, Ls11Frame::OnQuit)
    EVT_MENU(idMenuAbout, Ls11Frame::OnAbout)
    EVT_MENU(idMenuAboutAuthor, Ls11Frame::OnAboutAuthor)

    EVT_MENU(idMenuBlueColor, Ls11Frame::OnTextColorSelected)
    EVT_MENU(idMenuRedColor, Ls11Frame::OnTextColorSelected)
    EVT_MENU(idMenuGreenColor, Ls11Frame::OnTextColorSelected)

    EVT_MENU(idMenuBigFont, Ls11Frame::OnTextFontSelected)
    EVT_MENU(idMenuSmallFont, Ls11Frame::OnTextFontSelected)

END_EVENT_TABLE()

Ls11Frame::Ls11Frame(wxFrame *frame, const wxString& title)
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
    optionsMenu->AppendCheckItem(idMenuShowMotionInfo, wxT("Show &motion info"), _("Show motion info or no"));

    optionsMenu->AppendSeparator();

    optionsMenu->AppendRadioItem(idMenuBlueColor, wxT("&Blue text"), _("Set text blue"));
    optionsMenu->AppendRadioItem(idMenuRedColor, wxT("&Red text"), _("Set text red"));
    optionsMenu->AppendRadioItem(idMenuGreenColor, wxT("&Green text"), _("Set text green"));

    optionsMenu->AppendSeparator();

    optionsMenu->AppendRadioItem(idMenuBigFont, wxT("Big text"), _("Set big text"));
    optionsMenu->AppendRadioItem(idMenuSmallFont, wxT("Small text"), _("Set small text"));

    wxMenu* helpMenu = new wxMenu(_T(""));
    helpMenu->Append(idMenuAbout, _("&About\tF1"), _("Show info about this application"));
    helpMenu->Append(idMenuAboutAuthor, _("About auth&or"), _("Show info about this application's author"));

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


Ls11Frame::~Ls11Frame()
{
}

void Ls11Frame::OnClose(wxCloseEvent &event)
{
    Destroy();
}

void Ls11Frame::OnQuit(wxCommandEvent &event)
{
    Destroy();
}

void Ls11Frame::OnAbout(wxCommandEvent &event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void Ls11Frame::OnMotion(wxMouseEvent& event)
{
    xPos = event.GetPosition().x;
    yPos = event.GetPosition().y;

    this->Refresh(); // 每当鼠标移动，就让窗口刷新内容
}

void Ls11Frame::OnPaint(wxPaintEvent& event)
{
    bool showInfo = this->GetMenuBar()->IsChecked(idMenuShowMotionInfo);

    wxString txt;
    if (showInfo)
    {
        txt << wxT("鼠标位置:")  << xPos << wxT(" - ") << yPos;
    }
    else
    {
        txt = wxT("你可以选中\"Show motion info\"来显示鼠标位置");
    }

    static std::map<int, wxColor const*> colors =
    {
        { idMenuBlueColor,  wxBLUE },
        { idMenuRedColor, wxRED },
        { idMenuGreenColor, wxGREEN }
    };

    wxPaintDC dc(this); // 当前窗口客户区的“画板” （设备上下文）

    if (auto c = colors[this->selectedColorMenutItemId]; c)
    {
        dc.SetTextForeground(*c);
    }

    // 仅在选中大字体时，创建一个大字体并应用
    if (this->selectedFontMenuItemId == idMenuBigFont)
    {
        wxFont bigFont {
            wxSize(0, 20), // 宽高，可仅设置 高度
            wxFONTFAMILY_DEFAULT, // 字体家族
            wxFONTSTYLE_NORMAL, // 风格
            wxFONTWEIGHT_BOLD, // 粗体
            false, // 下划线
        };

        dc.SetFont(bigFont);
    }
    else
    {
        wxFont smallFont {
            wxSize(0, 14), // 宽高，可仅设置 高度
            wxFONTFAMILY_DEFAULT, // 字体家族
            wxFONTSTYLE_NORMAL, // 风格
            wxFONTWEIGHT_NORMAL, // 粗体
            false, // 下划线
        };

        dc.SetFont(smallFont);
    }

    wxPoint pos (xPos + 2 , yPos + 2);
    dc.DrawText(txt, pos);
}

void Ls11Frame::OnAboutAuthor(wxCommandEvent& event)
{
    wxString msg = wxT("关于作者南郁：帅气、智慧、没钱。");
    wxMessageBox(msg, _("About author"));
}

void Ls11Frame::OnTextColorSelected(wxCommandEvent& event)
{
    this->selectedColorMenutItemId = event.GetId(); // 记录选中的文本颜色菜单ID
}

void Ls11Frame::OnTextFontSelected(wxCommandEvent& event)
{
    this->selectedFontMenuItemId = event.GetId(); // 记录选中的字体大小菜单ID
}
