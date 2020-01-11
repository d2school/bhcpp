/***************************************************************
 * Name:      HelloInternetApp.cpp
 * Purpose:   Code for Application Class
 * Author:    NanYu (nanyu@sina.com)
 * Created:   2008-10-26
 * Copyright: NanYu (www.d2school.com)
 * License:
 **************************************************************/

#include "HelloInternetApp.h"

//(*AppHeaders
#include "HelloInternetMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(HelloInternetApp);

bool HelloInternetApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	HelloInternetDialog Dlg(0);
    	SetTopWindow(&Dlg);
    	Dlg.ShowModal();
    	wxsOK = false;
    }
    //*)
    return wxsOK;

}
