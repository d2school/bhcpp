/***************************************************************
 * Name:      HelloGUIMain.h
 * Purpose:   Defines Application Frame
 * Author:    NanYU (nanyu@sina.com)
 * Created:   2008-10-26
 * Copyright: NanYU (www.d2school.com)
 * License:
 **************************************************************/

#ifndef HELLOGUIMAIN_H
#define HELLOGUIMAIN_H

//(*Headers(HelloGUIDialog)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/statline.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class HelloGUIDialog: public wxDialog
{
    public:

        HelloGUIDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~HelloGUIDialog();

    private:

        //(*Handlers(HelloGUIDialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(HelloGUIDialog)
        static const long ID_STATICTEXT_WELCOME;
        static const long ID_BUTTON_ABOUT;
        static const long ID_STATICLINE1;
        static const long ID_BUTTON_QUIT;
        //*)

        //(*Declarations(HelloGUIDialog)
        wxButton* ButtonAbout;
        wxStaticText* StaticText1;
        wxBoxSizer* BoxSizer2;
        wxButton* ButtonQuit;
        wxStaticLine* StaticLine1;
        wxBoxSizer* BoxSizer1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // HELLOGUIMAIN_H
