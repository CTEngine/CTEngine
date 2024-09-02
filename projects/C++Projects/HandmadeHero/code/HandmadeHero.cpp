//========================================================================================//
//																												                                //
//																												                                //
//        								  			Welcome to Handmade Hero		          									//
//																												                                //
//																												                                //
//========================================================================================//

/*

  Author:		Armond Domina (ARM&)(ARM& - x64)
  Date:		9/01/2024

*/

/*

  STRUCTURAL TEMPLATE FOR CREATING OWN ENGINE/PROJECTS
  THIS WILL CHANGE 01, to 02 etc but this information is just placement, and not the actual build yet.
  This ensure that functions will work, and instances will create and actual code can be processed first before building.

  In Order for this program to function.  It has to be created right via using "Windows" rather than "Console"
  In Order to do so, Right Click on Project - > Go To Properties - > Left Pane "Linker" - > System - > SubSystem.
  Set this to Windows instead of Console, on a new project so this code will function properly.  Until We Figure out how to build
  It all via a Console App instead.

*/

#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <wingdi.h>

/*

struct tagWNDCLASSA
{
  UINT      style;
  WNDPROC   lpfnWndProc;
  int       cbClsExtra;
  int       cbWndExtra;
  HINSTANCE hInstance;
  HICON     hIcon;
  HCURSOR   hCursor;
  HBRUSH    hbrBackground;
  LPCSTR    lpszMenuName;
  LPCSTR    lpszClassName;
};

typedef struct tagWNDCLASSA
{
  UINT      style;
  WNDPROC   lpfnWndProc;
  int       cbClsExtra;
  int       cbWndExtra;
  HINSTANCE hInstance;
  HICON     hIcon;
  HCURSOR   hCursor;
  HBRUSH    hbrBackground;
  LPCSTR    lpszMenuName;
  LPCSTR    lpszClassName;
} WNDCLASSA, *PWNDCLASSA, *NPWNDCLASSA, *LPWNDCLASSA;

*/

// NEW (ARM&)

LRESULT CALLBACK
MainWindowCallback(HWND Window,
                  UINT Message,
                  WPARAM WParam,
                  LPARAM LParam)
{

  LRESULT Result = 0;

  // SWITCH STATMENT:
  switch(Message)
  {
      case WM_SIZE:
      {
          OutputDebugStringA("WM_SIZE \n");
      } break;
      case WM_DESTROY:
      {
          OutputDebugStringA("WM_DESTROY \n");
      } break;
      case WM_CLOSE:
      {
          OutputDebugStringA("WM_CLOSE \n");
          // DestroyWindow();
      } break;
      case WM_ACTIVATEAPP:
      {
          OutputDebugStringA("WM_ACTIVATEAPP \n");
      } break;
      case WM_PAINT:
      {
          PAINTSTRUCT Paint;
          HDC DeviceContext = BeginPaint(Window, &Paint);
          int X = Paint.rcPaint.left;
          int Y = Paint.rcPaint.top;
          int Width = Paint.rcPaint.right - Paint.rcPaint.left;
          int Height = Paint.rcPaint.bottom - Paint.rcPaint.top;
          static DWORD Operation = BLACKNESS;
          // PatBlt(DeviceContext, X, Y, Width, Height, WHITENESS);
          // PatBlt(DeviceContext, X, Y, Width, Height, BLACKNESS); 
          if(Operation == WHITENESS)
          {
            Operation = BLACKNESS;
          }
          else
          {
            Operation = WHITENESS;
          }
          EndPaint(Window, &Paint);
      } break;
      
      default:
      {
          // OutputDebugStringA("WM_DEFAULT \n");
          Result = DefWindowProc(Window, Message, WParam, LParam);
      } break;
  }

  return (Result);
}

int CALLBACK WinMain(
    HINSTANCE Instance,
    HINSTANCE PrevInstance,
    LPSTR CommandLine,
    int ShowCode)
{
  WNDCLASS WindowClass = {};

  // TODO (ARM&): Check if HREDRAW/VREDRAW/OWNDC still matter?
  // WindowClass.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW; // FLAGS Needed to Draw/Control Window.
  WindowClass.lpfnWndProc = MainWindowCallback;           // Handles Windows Procedures.
  WindowClass.hInstance = Instance;
  WindowClass.lpszClassName = "HandmadeHeroWindowClass";
  // WindowClass.hIcon;

  if(RegisterClassA(&WindowClass))
  {
    HWND WindowHandle =
        CreateWindowExA(
            0,
            WindowClass.lpszClassName,
            "Handmade Hero",
            WS_OVERLAPPEDWINDOW|WS_VISIBLE,
            CW_USEDEFAULT,
            CW_USEDEFAULT,
            CW_USEDEFAULT,
            CW_USEDEFAULT,
            0,
            0,
            Instance,
            0);

            /* These noted below, are what the above is replaced/represents by different variables below is the order used.

            // DWORD dwExStyle,
            // LPCTSTR lpClassName,
            // LPCTSTR lpWindowName,
            // DWORD dwStyle,
            // int x,
            // int y,
            // int nWidth,
            // int nheight,
            // HWND hWndParent,
            // HMENU hMenu,
            // HINSTANCE hInstance,
            // LPVOID lpParam);

            */

    if(WindowHandle) // THIS CAN BE OMITTED. (!= NULL)
    {
      for(;;)
      {
        MSG Message;
        BOOL MessageResult = GetMessageA(&Message, 0, 0, 0);
        if(MessageResult > 0)
        {
          // TranslateMessageA(&Message); // OMIT FOR LATER USE.
          DispatchMessageA(&Message);
        }
        else
        {
          break;
        }
      }
    }
    else
    {
      // TODO(ARM&): Logging
    }
  }
  else
  {
    // TODO(ARM&): Logging.
  }

  // NEW COMPLETE (ARM&)
  return 0;
}