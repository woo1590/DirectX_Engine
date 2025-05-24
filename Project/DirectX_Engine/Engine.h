#pragma once
class SceneManager;
class InputManager;
class Engine {
private:
    HWND hWnd;
    HINSTANCE hInstance;
    RECT windowSize;
    RECT originalWindowSize;
    HDC hDC;
    MSG msg;
    HACCEL hAccel;

private:
    std::chrono::system_clock::time_point prevTick;
    bool isRunning;
    static constexpr double Frame = 1 / 144.;

    InputManager* InputMgr;
    SceneManager* SceneMgr;
public:
    static Engine& GetInstance()
    {
        static Engine Instance;
        return Instance;
    }

    bool Initialize(HINSTANCE hInst, int nCmdShow);
    void Run();
    void Update(double dt);
    void Render();
    void Shutdown();

    InputManager* GetInputManager()const { return InputMgr; }   
    SceneManager* GetSceneManager()const { return SceneMgr; }
    HWND GetWindowHandle() const { return hWnd; }
    RECT GetWindowSize() const { return originalWindowSize; }
    static LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
private:
    bool InitWindow(HINSTANCE hInst, int nCmdShow);
};

