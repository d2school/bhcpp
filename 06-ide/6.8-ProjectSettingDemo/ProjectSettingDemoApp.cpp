/***************************************************************
 * Name:      ProjectSettingDemoApp.cpp
 * Purpose:   Code for Application Class
 * Author:    nanyu (nanyu@sina.com.cn)
 * Created:   2009-12-12
 * Copyright: nanyu (www.d2school.com)
 * License:
 **************************************************************/

#include "ProjectSettingDemoApp.h"

//(*AppHeaders
#include "ProjectSettingDemoMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(ProjectSettingDemoApp);

bool ProjectSettingDemoApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	ProjectSettingDemoDialog Dlg(0);
    	SetTopWindow(&Dlg);
    	Dlg.ShowModal();
    	wxsOK = false;
    }
    //*)
    return wxsOK;

}
