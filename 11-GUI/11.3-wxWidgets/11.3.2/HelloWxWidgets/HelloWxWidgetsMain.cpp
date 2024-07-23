/***************************************************************
 * Name:      HelloWxWidgetsMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    d2school (nanyu@d2school.com)
 * Created:   2023-08-05
 * Copyright: d2school (www.d2school)
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "HelloWxWidgetsMain.h"

//helper functions

BEGIN_EVENT_TABLE(HelloWxWidgetsFrame, wxFrame)
    EVT_CLOSE(HelloWxWidgetsFrame::OnClose)
    EVT_MENU(idMenuQuit, HelloWxWidgetsFrame::OnQuit)

    EVT_MOTION(HelloWxWidgetsFrame::OnMotion)
    EVT_PAINT(HelloWxWidgetsFrame::OnPaint)
END_EVENT_TABLE()

HelloWxWidgetsFrame::HelloWxWidgetsFrame(wxFrame *frame, const wxString& title)
    : wxFrame(frame, -1, title)
{
}


HelloWxWidgetsFrame::~HelloWxWidgetsFrame()
{
}

void HelloWxWidgetsFrame::OnClose(wxCloseEvent &event)
{
    Destroy();
}

void HelloWxWidgetsFrame::OnQuit(wxCommandEvent &event)
{
    Destroy();
}

void HelloWxWidgetsFrame::OnMotion(wxMouseEvent& event)
{
    this->xPos = event.GetPosition().x;
    this->yPos = event.GetPosition().y;

    this->Refresh();
}

void HelloWxWidgetsFrame::OnPaint(wxPaintEvent& event)
{
    wxPaintDC dc (this);

    wxString txt;
    txt << wxT("[") << xPos << wxT(" | ") << yPos << wxT("]-来自d2school (Windows)");
    dc.DrawText(txt, xPos + 10, yPos + 10);
}


