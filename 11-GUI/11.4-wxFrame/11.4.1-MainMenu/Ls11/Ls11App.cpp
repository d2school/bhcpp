/***************************************************************
 * Name:      Ls11App.cpp
 * Purpose:   Code for Application Class
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

#include "Ls11App.h"
#include "Ls11Main.h"

IMPLEMENT_APP(Ls11App);

bool Ls11App::OnInit()
{
    Ls11Frame* frame = new Ls11Frame(0L, _("wxWidgets Application Template"));
    frame->SetIcon(wxICON(aaaa)); // To Set App Icon
    frame->Show();
    
    return true;
}
