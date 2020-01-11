/***************************************************************
 * Name:      HelloGUIApp.cpp
 * Purpose:   Code for Application Class
 * Author:    NanYU (nanyu@sina.com)
 * Created:   2008-10-26
 * Copyright: NanYU (www.d2school.com)
 * License:
 **************************************************************/

#include "HelloGUIApp.h"

//(*AppHeaders
#include "HelloGUIMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(HelloGUIApp);

bool HelloGUIApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	HelloGUIDialog Dlg(0);
    	SetTopWindow(&Dlg);
    	Dlg.ShowModal();
    	wxsOK = false;
    }
    //*)
    return wxsOK;

}
