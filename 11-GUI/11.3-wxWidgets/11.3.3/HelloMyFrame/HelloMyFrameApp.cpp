/***************************************************************
 * Name:      HelloMyFrameApp.cpp
 * Purpose:   Code for Application Class
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

#include "HelloMyFrameApp.h"
#include "HelloMyFrameMain.h"

IMPLEMENT_APP(HelloMyFrameApp);

bool HelloMyFrameApp::OnInit()
{
    HelloMyFrameFrame* frame = new HelloMyFrameFrame(0L, _("wxWidgets Application Template"));
    frame->SetIcon(wxICON(aaaa)); // To Set App Icon
    frame->Show();
    
    return true;
}
