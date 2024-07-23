/***************************************************************
 * Name:      HelloWxWidgetsApp.cpp
 * Purpose:   Code for Application Class
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

#include "HelloWxWidgetsApp.h"
#include "HelloWxWidgetsMain.h"

IMPLEMENT_APP(HelloWxWidgetsApp);

bool HelloWxWidgetsApp::OnInit()
{
    HelloWxWidgetsFrame* frame = new HelloWxWidgetsFrame(0L, _("wxWidgets Application Template"));
    frame->SetIcon(wxICON(aaaa)); // To Set App Icon
    frame->Show();
    
    return true;
}
