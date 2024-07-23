/***************************************************************
 * Name:      HelloMenuApp.cpp
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

#include "HelloMenuApp.h"
#include "HelloMenuMain.h"

IMPLEMENT_APP(HelloMenuApp);

bool HelloMenuApp::OnInit()
{
    HelloMenuFrame* frame = new HelloMenuFrame(0L, _("wxWidgets Application Template"));
    frame->SetIcon(wxICON(aaaa)); // To Set App Icon
    frame->Show();

    return true;
}
