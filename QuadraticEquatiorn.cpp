// QuadraticEquatiorn.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "QuadraticEquatiorn.h"
#include "CalcManager.h"

#define MAX_LOADSTRING 100
#define IDC_BUTTON_U1 5001

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Controls Handles:
HWND hButtonU1;
HWND hButton1, hButton2, hButton3;
HWND hEdit1, hEdit2, hEdit3, hEdit4;

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    Calc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_QUADRATICEQUATIORN, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_QUADRATICEQUATIORN));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}

//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_QUADRATICEQUATIORN));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_QUADRATICEQUATIORN);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
	case WM_CREATE:
		{
			SetWindowText(hWnd, L"Квадратные уравнения");
			MoveWindow(hWnd, 485, 220, 400, 200, true);
			hButtonU1 = CreateWindowEx(0, L"BUTTON", L"Открыть программу", WS_CHILD | 
				WS_VISIBLE, 20, 40, 340, 35, hWnd, (HMENU)IDC_BUTTON_U1, hInst, NULL);
		}
		break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            switch (wmId)
            {
			case IDC_BUTTON_U1:
				{					
					DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, Calc);
				}
				break;
            case IDM_ABOUT:
				{
					DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
				}
                break;
            case IDM_EXIT:
				{
					DestroyWindow(hWnd);
				}
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

//
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

//
INT_PTR CALLBACK Calc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		{
			hButton1 = GetDlgItem(hDlg, IDC_BUTTON1);
			hButton2 = GetDlgItem(hDlg, IDC_BUTTON2);
			hButton3 = GetDlgItem(hDlg, IDC_BUTTON3);
			hEdit1 = GetDlgItem(hDlg, IDC_EDIT1);
			hEdit2 = GetDlgItem(hDlg, IDC_EDIT2);
			hEdit3 = GetDlgItem(hDlg, IDC_EDIT3);
			hEdit4 = GetDlgItem(hDlg, IDC_EDIT4);
		}
		return (INT_PTR)TRUE;
	case WM_COMMAND:
		{
			int wmId = LOWORD(wParam);	
			switch (wmId)
			{
			case IDC_BUTTON1:
				{
                    TCHAR buff[100];
                    TCHAR buff1[100];
                    TCHAR buff2[100];
                    TCHAR buff3[512];
                    TCHAR journal[1024];

                    GetWindowText(hEdit1, buff1, 100);
                    GetWindowText(hEdit2, buff2, 100);
                    GetWindowText(hEdit3, buff3, 100);
                    
                    if (lstrlen(buff1) == 0)
                    {
                        MessageBox(hDlg, L"Вы не ввели 1-ый коэффициент", L"Предупреждение", MB_OK | MB_ICONERROR);
                        SetFocus(hEdit1);
                    }
                    else if (lstrlen(buff2) == 0)
                    {
                        MessageBox(hDlg, L"Вы не ввели 2-ый коэффициент", L"Предупреждение", MB_OK | MB_ICONERROR);
                        SetFocus(hEdit2);
                    }
                    else if (lstrlen(buff3) == 0)
                    {
                        MessageBox(hDlg, L"Вы не ввели 3-ый коэффициент", L"Предупреждение", MB_OK | MB_ICONERROR);
                        SetFocus(hEdit3);
                    }
                    else
                    {
                        try
                        {
                            double a = _wtof(buff1);
                            double b = _wtof(buff2);
                            double c = _wtof(buff3);

                            if (a == 0 && lstrcmp(buff1, L"0") != 0)
                            {
                                SetWindowText(hEdit1, L"");
                                throw L"Ошибка формата ввода 1-го коэффициента";
                            }
                            else if (b == 0 && lstrcmp(buff2, L"0") != 0)
                            {
                                SetWindowText(hEdit2, L"");
                                throw L"Ошибка формата ввода 2-го коэффициента";
                            }
                            else if (c == 0 && lstrcmp(buff3, L"0") != 0)
                            {
                                SetWindowText(hEdit3, L"");
                                throw L"Ошибка формата ввода 3-го коэффициента";
                            }

                            CalcManager* cm = new CalcManager();
                            lstrcpy(buff, cm->calculateQuadricEquation(a, b, c));
                            delete(cm);

                            GetWindowText(hEdit4, journal, 1024);
                            lstrcat(journal, buff);
                            lstrcat(journal, L"\r\n");
                            SetWindowText(hEdit4, journal);

                            SetWindowText(hEdit1, L"");
                            SetWindowText(hEdit2, L"");
                            SetWindowText(hEdit3, L"");
                        }
                        catch (const TCHAR* err_mess)
                        {
                            MessageBox(hDlg, err_mess, L"Ошибка", MB_OK | MB_ICONERROR);
                        }
                    }

				}
				break;
			case IDC_BUTTON2:
				{
					SetWindowText(hEdit1, L"");
					SetWindowText(hEdit2, L"");
					SetWindowText(hEdit3, L"");
				}
				break;
			case IDC_BUTTON3:
				{
					SetWindowText(hEdit4, L"");
				}
				break;
			}
		}
		return (INT_PTR)TRUE;
	case WM_CLOSE:
		{
			EndDialog(hDlg, 0);
		}
		return (INT_PTR)TRUE;
	}
	return (INT_PTR)FALSE;
}