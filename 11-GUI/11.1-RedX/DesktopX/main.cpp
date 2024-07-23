#include <windows.h>
#include <commctrl.h>
#include <stdio.h>
#include "resource.h"

HINSTANCE hInst;

int DesktopWidth, DesktopHeight; // �����ȡ��߶�

unsigned int ID_TIMER = 999; // ��ʱ��ID

void CALLBACK OnTimer(HWND hWnd, UINT iMsg, UINT_PTR iTimerID, DWORD dwTime)
{
    auto hDC = ::GetDC(nullptr); // �õ�������� DC �������塱��

    if (hDC != nullptr)
    {
        auto pen = ::CreatePen(PS_SOLID, 10, RGB(0xff, 0, 0)); // �������10����ɫ�ı�

        // �� pen ���ʣ� �ŵ� ���� ��DC���豸�����ģ��ϣ�
        ::SelectObject(hDC, pen);

        ::MoveToEx(hDC, 0, 0, nullptr); // �ƶ��� DC �����Ͻ�
        ::LineTo(hDC, DesktopWidth, DesktopHeight); // �����Ͻǻ��ߵ����½�

        ::MoveToEx(hDC, DesktopWidth, 0, nullptr); // �ƶ������Ͻ�
        ::LineTo(hDC, 0, DesktopHeight);    // �����Ͻǻ��ߵ����½�

        ::DeleteObject(pen); // ɾ������Դ
        ::ReleaseDC(nullptr, hDC); // �黹DC
    }
}

BOOL CALLBACK DlgMain(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
    case WM_INITDIALOG: // ��ʼ���Ի���
    {
        DesktopWidth = ::GetSystemMetrics(SM_CXFULLSCREEN);
        DesktopHeight = ::GetSystemMetrics(SM_CYFULLSCREEN);

        ::SetTimer(hwndDlg, ID_TIMER, 80 /*����*/, OnTimer);
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
