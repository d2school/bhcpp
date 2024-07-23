/***************************************************************
 * Name:      HelloMyFrameMain.h
 * Purpose:   Defines Application Frame
 * Author:    d2school (nanyu@d2school.com)
 * Created:   2024-04-11
 * Copyright: d2school (www.d2school)
 * License:
 **************************************************************/

#ifndef HELLOMYFRAMEMAIN_H
#define HELLOMYFRAMEMAIN_H

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "HelloMyFrameApp.h"

class HelloMyFrameFrame: public wxFrame
{
    public:
        HelloMyFrameFrame(wxFrame *frame, const wxString& title);
        ~HelloMyFrameFrame();
    private:
        enum
        {
            idMenuQuit = 1000,
            idMenuAbout,

            idMenueAboutAuthor,
            idMenuShowMotionInfo, // 菜单项 是否显示 鼠标信息

            idMenuBlueText, // 菜单项 设置为蓝色文本
            idMenuRedText,  // 菜单项 设置为红色文本
            idMenuGreenText // 菜单项 设置为绿色文本
        };

        void OnClose(wxCloseEvent& event);
        void OnQuit(wxCommandEvent& event);

        void OnMotion(wxMouseEvent& event); // 鼠标移动事件响应函数
        void OnPaint(wxPaintEvent& event); // 窗口客户区绘图事件响应函数

        void OnAbout(wxCommandEvent& event);
        void OnAboutAuthor(wxCommandEvent& event); // 关于作者

        void OnTextColorSelected(wxCommandEvent& event); // 处理选中文本颜色

        int xPos, yPos;
        int selectedColorMenuItemId = idMenuBlueText;

        DECLARE_EVENT_TABLE()
};


#endif // HELLOMYFRAMEMAIN_H
