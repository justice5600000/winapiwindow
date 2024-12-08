#include <windows.h>
#include <stdio.h>
#include <stdbool.h>

// main entry function
int APIENTRY WinMain (HINSTANCE hInst,
                      HINSTANCE hPrevInst,
                      LPSTR     lpCmdLine,
                      int       nCmdShow)
{
    // local vars
    int count = 0;
    WNDCLASS wc; // main window structure
    MSG msg; // message object
    HWND hwnd; // main window handle

    // init main window class structure
    ZeroMemory(&wc, sizeof(WNDCLASS));

    // set individual members
    wc.style = CS_HREDRAW | CS_VREDRAW; // window redraw styles
    wc.lpfnWndProc = (WNDPROC) DefWindowProc; // default window procedure
    wc.hInstance = hInst; // current process instance
    wc.hCursor = LoadCursor(NULL, IDC_ARROW); // mouse cursor arrow
    wc.hbrBackground = (HBRUSH)(COLOR_BACKGROUND); // background brush
    wc.lpszClassName = "MyBasicwindow"; // name of window class

    // register class to windows subsystem
    RegisterClass(&wc);

    // create top main window with class
    hwnd = CreateWindow("MyBasicwindow", // name of the window class
                        "WINDOW DEMOOOO", // title of the window
                        WS_OVERLAPPEDWINDOW, // style, overlapping top window
                        CW_USEDEFAULT, // x
                        0, // y
                        CW_USEDEFAULT, // width
                        0, // height
                        NULL, // parent windows (windows above)
                        NULL, // menu bar (none used)
                        hInst, // process instance handle
                        NULL); // extra param, no param
    // show created window
    ShowWindow(hwnd, nCmdShow);

    // update window for paint
    UpdateWindow(hwnd);

    // get messages from windows
    bool loop = true;

    while(loop) // main program loop
    {
        GetMessage(&msg, NULL, 0, 0);
        DispatchMessage(&msg);
     

    }

    // return 0 (sucsess)
    return 0;

}

