#include "Application.h"

Application::Application(const std::string& windowTitle, int windowWidth, int windowHeight)
    :   _window(nullptr),
        _renderer(nullptr),
        m_running(false),
        m_windowTitle(windowTitle),
        _windowWidth(windowWidth),
        _windowHeight(windowHeight) 
        {
            m_running = initSDL();
        }

Application::~Application() 
{
    quitSDL();
}

void Application::run() 
{
    while (m_running) {
        handleEvents();
        update();
        render();
    }
}

bool Application::initSDL() 
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    _window = SDL_CreateWindow(m_windowTitle.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, _windowWidth, _windowHeight, SDL_WINDOW_SHOWN);
    if (_window == nullptr) 
    {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (_renderer == nullptr) 
    {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    _surface = SDL_GetWindowSurface(_window);
    if (_surface == nullptr) 
    {
        std::cerr << "Surface could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    _renderingManager = RenderingManager(_renderer, _surface, &_camera);
    return true;
}

void Application::quitSDL() 
{
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

void Application::handleEvents() 
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) 
    {
        _inputMangager.handleEvent(event);
        if (_inputMangager.isKeyDown(SDL_SCANCODE_ESCAPE))
        {
            m_running = false;
        }
    }
}

void Application::update() 
{
    // Update your application state here
}

void Application::render() 
{
    _renderingManager.clearSurface(Vector3<unsigned>(0, 0, 0));
    SDL_Texture *_texture = _renderingManager.getTexture();
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    SDL_RenderClear(_renderer);
    SDL_RenderCopy(_renderer, _texture, NULL, NULL);
    

    // Render your application objects here

    SDL_RenderPresent(_renderer);
}