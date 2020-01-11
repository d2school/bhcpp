/***************************************************************
 * Name:      HelloGUILayoutMain.h
 * Purpose:   Defines Application Frame
 * Author:    zhuangyan (nanu@sina.com)
 * Created:   2015-02-24
 * Copyright: zhuangyan (www.d2school.com)
 * License:
 **************************************************************/

#ifndef HELLOGUILAYOUTMAIN_H
#define HELLOGUILAYOUTMAIN_H

//(*Headers(HelloGUILayoutDialog)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/statline.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class HelloGUILayoutDialog: public wxDialog
{
    public:

        HelloGUILayoutDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~HelloGUILayoutDialog();

    private:

        //(*Handlers(HelloGUILayoutDialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton3Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(HelloGUILayoutDialog)
        static const long ID_STATICTEXT1;
        static const long ID_BUTTON3;
        static const long ID_BUTTON1;
        static const long ID_STATICLINE1;
        static const long ID_BUTTON2;
        //*)

        //(*Declarations(HelloGUILayoutDialog)
        wxButton* Button1;
        wxStaticText* StaticText1;
        wxBoxSizer* BoxSizer2;
        wxButton* Button2;
        wxButton* Button3;
        wxStaticLine* StaticLine1;
        wxBoxSizer* BoxSizer1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // HELLOGUILAYOUTMAIN_H
