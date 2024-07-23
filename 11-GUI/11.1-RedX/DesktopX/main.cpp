#include <windows.h>
#include <commctrl.h>
#include <stdio.h>
#include "resource.h"

HINSTANCE hInst;

int DesktopWidth, DesktopHeight; // 桌面宽度、高度

unsigned int ID_TIMER = 999; // 定时器ID

void CALLBACK OnTimer(HWND hWnd, UINT iMsg, UINT_PTR iTimerID, DWORD dwTime)
{
    auto hDC = ::GetDC(nullptr); // 得到主桌面的 DC （“画板”）

    if (hDC != nullptr)
    {
        auto pen = ::CreatePen(PS_SOLID, 10, RGB(0xff, 0, 0)); // 创建宽度10，红色的笔

        // 把 pen （笔） 放到 画板 （DC，设备上下文）上：
        ::SelectObject(hDC, pen);

        ::MoveToEx(hDC, 0, 0, nullptr); // 移动到 DC 的左上角
        ::LineTo(hDC, DesktopWidth, DesktopHeight); // 从左上角画线到右下角

        ::MoveToEx(hDC, DesktopWidth, 0, nullptr); // 移动到右上角
        ::LineTo(hDC, 0, DesktopHeight);    // 从右上角画线到左下角

        ::DeleteObject(pen); // 删除笔资源
        ::ReleaseDC(nullptr, hDC); // 归还DC
    }
}

BOOL CALLBACK DlgMain(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
    case WM_INITDIALOG: // 初始化对话框
    {
        DesktopWidth = ::GetSystemMetrics(SM_CXFULLSCREEN);
        DesktopHeight = ::GetSystemMetrics(SM_CYFULLSCREEN);

        ::SetTimer(hwndDlg, ID_TIMER, 80 /*毫秒*/, OnTimer);
    }
    return TRUE;

    case WM_CLOSE:
    {
        ::KillTimer(hwndDlg, ID_TIMER);
        EndDialog(hwndDlg, 0);
    }
    return TRUE;

    case WM_COMMAND:
    {
        switch(LOWORD(wParam))
        {
        }
    }
    return TRUE;
    }
    return FALSE;
}


int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    hInst=hInstance;
    InitCommonControls();
    return DialogBox(hInst, MAKEINTRESOURCE(DLG_MAIN), NULL, (DLGPROC)DlgMain);
}
