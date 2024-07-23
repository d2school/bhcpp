/***************************************************************
 * Name:      Ls11Main.h
 * Purpose:   Defines Application Frame
 * Author:    d2school (nanyu@d2school.com)
 * Created:   2024-04-14
 * Copyright: d2school (www.d2school)
 * License:
 **************************************************************/

#ifndef LS11MAIN_H
#define LS11MAIN_H

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "Ls11App.h"

class Ls11Frame: public wxFrame
{
    public:
        Ls11Frame(wxFrame *frame, const wxString& title);
        ~Ls11Frame();
    private:
        enum
        {
            idMenuQuit = 1000,
            idMenuAbout,

            idMenuAboutAuthor,  // 关于作者
            idMenuShowMotionInfo, // 是否显示鼠标位置信息

            idMenuBlueColor, // 蓝色
            idMenuRedColor, // 红色
            idMenuGreenColor, // 绿色

            idMenuBigFont, // 大字体
            idMenuSmallFont // 小字体
        };

        void OnClose(wxCloseEvent& event);
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnAboutAuthor(wxCommandEvent& event);

        // 鼠标移动事件响应函数
        void OnMotion(wxMouseEvent& event);
        // 窗口客户区绘图事件响应函数
        void OnPaint(wxPaintEvent& event);

        // 选择颜色的菜单项共用的事件响应函数
        void OnTextColorSelected(wxCommandEvent& event);

        // 选择字体（大小）的菜单项共用的事件响应函数
        void OnTextFontSelected(wxCommandEvent& event);

        int xPos, yPos; // 用于记住当前鼠标坐标
        int selectedColorMenutItemId = idMenuBlueColor; // 记录当前用户选中哪一个“颜色”菜单项
        int selectedFontMenuItemId = idMenuBigFont; // 默认大字体

        DECLARE_EVENT_TABLE()
};


#endif // LS11MAIN_H
