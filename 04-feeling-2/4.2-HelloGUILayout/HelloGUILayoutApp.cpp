/***************************************************************
 * Name:      HelloGUILayoutApp.cpp
 * Purpose:   Code for Application Class
 * Author:    zhuangyan (nanu@sina.com)
 * Created:   2015-02-24
 * Copyright: zhuangyan (www.d2school.com)
 * License:
 **************************************************************/

#include "HelloGUILayoutApp.h"

//(*AppHeaders
#include "HelloGUILayoutMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(HelloGUILayoutApp);

bool HelloGUILayoutApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	HelloGUILayoutDialog Dlg(0);
    	SetTopWindow(&Dlg);
    	Dlg.ShowModal();
    	wxsOK = false;
    }
    //*)
    return wxsOK;

}
