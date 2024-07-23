/***************************************************************
 * Name:      HelloWxWidgetsMain.h
 * Purpose:   Defines Application Frame
 * Author:    d2school (nanyu@d2school.com)
 * Created:   2023-08-05
 * Copyright: d2school (www.d2school)
 * License:
 **************************************************************/

#ifndef HELLOWXWIDGETSMAIN_H
#define HELLOWXWIDGETSMAIN_H

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "HelloWxWidgetsApp.h"

class HelloWxWidgetsFrame: public wxFrame
{
    public:
        HelloWxWidgetsFrame(wxFrame *frame, const wxString& title);
        ~HelloWxWidgetsFrame();
    private:
        enum
        {
            idMenuQuit = 1000,
            idMenuAbout
        };
        void OnClose(wxCloseEvent& event);
        void OnQuit(wxCommandEvent& event);

        void OnMotion(wxMouseEvent& event);
        void OnPaint(wxPaintEvent& event);

        DECLARE_EVENT_TABLE()

    private:
        int xPos = 0, yPos = 0;
};


#endif // HELLOWXWIDGETSMAIN_H
