/***************************************************************
 * Name:      HelloMenuMain.h
 * Purpose:   Defines Application Frame
 * Author:    d2school (nanyu@d2school.com)
 * Created:   2024-04-11
 * Copyright: d2school (www.d2school)
 * License:
 **************************************************************/

#ifndef HELLOMENUMAIN_H
#define HELLOMENUMAIN_H

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "HelloMenuApp.h"

class HelloMenuFrame: public wxFrame
{
    public:
        HelloMenuFrame(wxFrame *frame, const wxString& title);
        ~HelloMenuFrame();
    private:
        enum
        {
            idMenuQuit = 1000,
            idMenuAbout,
            idMenuAboutAuthor, // 关于作者

            idMenuShowMotionInfo, // 是否显示鼠标位置

            idMenuBlueText, // 设置蓝色文本
            idMenuRedText, // 设置红色文本
        };
        void OnClose(wxCloseEvent& event);
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnAboutAuthor(wxCommandEvent& event); // “关于作者” 菜单项事件响应函数

        void OnMontion(wxMouseEvent& event); // 鼠标移动事件响应函数
        void OnPaint(wxPaintEvent& event); // 窗口绘图事件响应函数
        void OnTextColorSelected(wxCommandEvent& event); // 设置文本颜色事件响应函数

        int xPos, yPos;
        int selectedColorId = idMenuBlueText;

        DECLARE_EVENT_TABLE()
};


#endif // HELLOMENUMAIN_H
