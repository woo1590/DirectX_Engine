#include "pch.h"
#include "Engine.h"
#include "InputManager.h"
#include "SceneManager.h"

bool Engine::InitWindow(HINSTANCE hInst, int nCmdShow)
{
    const wchar_t* CLASS_NAME = L"MyGameWindowClass";

    WNDCLASSEX wc = {};
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
    wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszMenuName = nullptr;
    wc.lpszClassName = CLASS_NAME;
    wc.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);

    if (!RegisterClassEx(&wc)) {
        OutputDebugString(L"[Engine] RegisterClassEx failed\n");
        return false;
    }

    originalWindowSize = { 0, 0, 800, 600 };
    windowSize = originalWindowSize;

    AdjustWindowRect(&windowSize, WS_OVERLAPPEDWINDOW, FALSE);

    hWnd = CreateWindowW(
        CLASS_NAME, L"My Game Window",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        windowSize.right - windowSize.left,
        windowSize.bottom - windowSize.top,
        nullptr, nullptr, hInstance, nullptr
    );

    if (!hWnd) {
        OutputDebugString(L"[Engine] CreateWindow failed\n");
        return false;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return true;
}

bool Engine::Initialize(HINSTANCE hInst, int nCmdShow)
{
    hInstance = hInst;

    msg.message = WM_NULL;

    if (!InitWindow(hInstance, nCmdShow))
    {
        return false;
    }

    hDC = GetDC(hWnd);

    /*-------------게임 내부 초기화------------*/
    prevTick = std::chrono::system_clock::now();
    InputMgr = new InputManager;
    SceneMgr = new SceneManager;

    InputMgr->Initialize();
    SceneMgr->Initialize();
    isRunning = true;
}

void Engine::Run()
{
    while (isRunning)
    {
        auto now = std::chrono::system_clock::now();
        double dt = std::chrono::duration<double>(now - prevTick).count();

        if (dt > Engine::Frame * 2)
        {
            dt = Frame;
        }
        if (dt >= Frame)
        {
            prevTick = now;
            if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
            {
                if (WM_QUIT == msg.message) return;

                if (!TranslateAccelerator(msg.hwnd, hAccel, &msg))
                {
                    TranslateMessage(&msg);
                    DispatchMessage(&msg);
                }
            }

            Update(dt);
            Render();
        }
    }
}

void Engine::Update(double dt)
{
    InputMgr->Update();
    SceneMgr->Update(dt);
}

void Engine::Render()
{
    HDC memDC = CreateCompatibleDC(hDC);
    HBITMAP bitmap = CreateCompatibleBitmap(hDC, windowSize.right - windowSize.left, windowSize.bottom - windowSize.top);
    HBITMAP oldBitmap = (HBITMAP)SelectObject(memDC, bitmap);

    HBRUSH brush = CreateSolidBrush(RGB(255, 255, 255));
    FillRect(memDC, &windowSize, brush);
    DeleteObject(brush);

    SceneMgr->Render(memDC);

    BitBlt(hDC, 0, 0, windowSize.right, windowSize.bottom, memDC, 0, 0, SRCCOPY);

    SelectObject(memDC, oldBitmap);
    DeleteObject(bitmap);
    DeleteDC(memDC);
}

void Engine::Shutdown()
{
    DestroyWindow(hWnd);
}


LRESULT CALLBACK Engine::WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_KEYDOWN:
        break;
    case WM_KEYUP:
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, msg, wParam, lParam);
    }
    return 0;
}
