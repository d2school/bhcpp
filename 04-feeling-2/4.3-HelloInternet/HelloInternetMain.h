/***************************************************************
 * Name:      HelloInternetMain.h
 * Purpose:   Defines Application Frame
 * Author:    NanYu (nanyu@sina.com)
 * Created:   2008-10-26
 * Copyright: NanYu (www.d2school.com)
 * License:
 **************************************************************/

#ifndef HELLOINTERNETMAIN_H
#define HELLOINTERNETMAIN_H

//(*Headers(HelloInternetDialog)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/statline.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class HelloInternetDialog: public wxDialog
{
    public:

        HelloInternetDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~HelloInternetDialog();

    private:

        //(*Handlers(HelloInternetDialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton3Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(HelloInternetDialog)
        static const long ID_STATICTEXT2;
        static const long ID_TEXTCTRL1;
        static const long ID_BUTTON3;
        static const long ID_STATICTEXT1;
        static const long ID_BUTTON1;
        static const long ID_STATICLINE1;
        static const long ID_BUTTON2;
        //*)

        //(*Declarations(HelloInternetDialog)
        wxStaticText* StaticText2;
        wxButton* Button1;
        wxStaticText* StaticText1;
        wxBoxSizer* BoxSizer2;
        wxButton* Button2;
        wxButton* Button3;
        wxStaticLine* StaticLine1;
        wxBoxSizer* BoxSizer1;
        wxTextCtrl* TextCtrl1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // HELLOINTERNETMAIN_H
