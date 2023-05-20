#pragma once

#include <SDL2/SDL.h>

#include "Geometry.h"
#include "Camera.h"
#include "Logger.h"
#include "Color.h"

class RenderingManager
{
    public:
        RenderingManager(SDL_Renderer *renderer = nullptr,
                         SDL_Surface *surface   = nullptr,
                         Camera *camera         = nullptr,
                         Logger *logger         = nullptr)
            :   _renderer{renderer},
                _surface(surface),
                _camera(camera),
                _logger(logger) {}
    private:
        SDL_Renderer *_renderer;
        SDL_Surface *_surface;
        Camera *_camera;
        Logger *_logger;
        std::pair<int, int> _screenSize{0, 0};

        std::pair<int, int> _toScreenSpace(int &x, int &y);
        template <typename T>    
        void _render(Model<T>);

        template <typename T>    
        void _drawTriangle(Triangle<T> tri, Vector3<unsigned> color = Vector3<unsigned>(0, 255, 0));

        template <typename T>    
        void _drawTriangle(Vector3<T> v, Vector3<unsigned> color = Vector3<unsigned>(0, 255, 0));

        template <typename T>    
        void _drawLine(Vector2<T> a, Vector2<T> b, Vector3<unsigned> color);

        void _drawPixel(int x,
                        int y,
                        Vector3<unsigned> color);
    public:
        template <typename T>
        void renderModels(std::vector<Model<T>> &models);

        void clearSurface(Vector3<unsigned> rgb);
        void setScreenSize(int &screenWidth, int &screenHeight);
        SDL_Texture *getTexture();
};