#define SDL_MAIN_HANDLED

#include <SDL2/SDL.h>
#include <string>
#include <iostream>

#include "Geometry.h"
#include "InputManager.h"
#include "RenderingManager.h"
#include "Camera.h"
#include "Logger.h"

class Application {
public:
    Application(const std::string& windowTitle,
                int windowWidth,
                int windowHeight);
    ~Application();

    void run();

private:
    bool initSDL();
    void quitSDL();

    void handleEvents();
    void update();
    void render();

    SDL_Window* _window     = nullptr;
    SDL_Renderer* _renderer = nullptr;
    SDL_Surface* _surface   = nullptr;
    bool m_running;

    std::string m_windowTitle;
    int _windowWidth;
    int _windowHeight;

    Camera _camera;
    InputManager _inputMangager;
    RenderingManager _renderingManager;
    Logger _logger;
};