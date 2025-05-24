#include "pch.h"
#include "Engine.h"

#define MAX_LOADSTRING 100

HINSTANCE hInst;                      
WCHAR szTitle[MAX_LOADSTRING];        
WCHAR szWindowClass[MAX_LOADSTRING];  

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    Engine& Game = Engine::GetInstance();

    if (!Game.Initialize(hInstance, nCmdShow)) return -1;
    Game.Run();
    Game.Shutdown();

    return 0;
}