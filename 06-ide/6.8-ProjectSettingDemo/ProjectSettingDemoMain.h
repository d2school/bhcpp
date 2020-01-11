/***************************************************************
 * Name:      ProjectSettingDemoMain.h
 * Purpose:   Defines Application Frame
 * Author:    nanyu (nanyu@sina.com.cn)
 * Created:   2009-12-12
 * Copyright: nanyu (www.d2school.com)
 * License:
 **************************************************************/

#ifndef PROJECTSETTINGDEMOMAIN_H
#define PROJECTSETTINGDEMOMAIN_H

//(*Headers(ProjectSettingDemoDialog)
#include <wx/dialog.h>
//*)

class ProjectSettingDemoDialog: public wxDialog
{
    public:

        ProjectSettingDemoDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~ProjectSettingDemoDialog();

    private:

        //(*Handlers(ProjectSettingDemoDialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnResize(wxSizeEvent& event);
        //*)

        //(*Identifiers(ProjectSettingDemoDialog)
        //*)

        //(*Declarations(ProjectSettingDemoDialog)
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // PROJECTSETTINGDEMOMAIN_H
