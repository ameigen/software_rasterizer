#include "RenderingManager.h"
        
template <typename T>
void RenderingManager::renderModels(std::vector<Model<T>> &models)
{
    ;
}

void RenderingManager::clearSurface(Vector3<unsigned> rgb)
{
    SDL_FillRect(_surface, NULL, SDL_MapRGB(_surface->format, rgb[0], rgb[1], rgb[2]));
    Vector3<float> a(0, 50, 100);
    a = _camera->pointToCameraSpace(a);
    //_drawTriangle(Vector3<int>(0, 50, 100), Vector3<unsigned>(122, 122, 0));  
    _drawLine(Vector2<int>(-100, -100), Vector2<int>(-100, 100), Colors::RED);
    _drawLine(Vector2<int>(-100, 100), Vector2<int>(100, 100), Colors::GREEN);
    _drawLine(Vector2<int>(100, 100), Vector2<int>(100, -100), Colors::BLUE);
    _drawLine(Vector2<int>(100, -100), Vector2<int>(-100, -100), Colors::PINK);
    _drawPixel(0, 0, Colors::BLUE);
}

SDL_Texture* RenderingManager::getTexture()
{
    return SDL_CreateTextureFromSurface(_renderer, _surface);
}

void RenderingManager::setScreenSize(int &screenWidth, int &screenHeight)
{
    _screenSize = std::pair<int, int>{screenWidth, screenHeight};
}

void RenderingManager::_drawPixel(int x,
                                  int y,
                                  Vector3<unsigned> color)
{
    std::pair<int, int> _screenSpace = _toScreenSpace(x, y);
    Uint32 *_pixels = static_cast<Uint32*>(_surface->pixels);
    _pixels[_screenSpace.second * _surface->w + _screenSpace.first] = SDL_MapRGB(_surface->format, color[0], color[1], color[2]);
    _logger->log(DEBUG, "Painting pixel at canvas position (", _screenSpace.first, ',', _screenSpace.second, ") and centered (" , x, ',', y, ')');
}

std::pair<int, int> RenderingManager::_toScreenSpace(int &x, int &y)
{
    int _screenSpaceX = x + _screenSize.first / 2,
        _screenSpaceY = _screenSize.second / 2 - y;
    return std::pair<int, int>{_screenSpaceX, _screenSpaceY};
}
template <typename T>    
void RenderingManager::_render(Model<T>)
{
    ;
}

template <typename T>    
void RenderingManager::_drawTriangle(Triangle<T> tri,
                                     Vector3<unsigned> color)
{
    _logger->log(DEBUG, "Rendering triangle: ", tri);
    _drawLine(Vector2<T>(tri[0]), (tri[0]),
              Vector2<T>(tri[1], tri[1]),
              color);
    _drawLine(Vector2<T>(tri[1]), (tri[1]),
              Vector2<T>(tri[2], tri[2]),
              color);
    _drawLine(Vector2<T>(tri[2]), (tri[2]),
              Vector2<T>(tri[3], tri[3]),
              color);
}

template <typename T>    
void RenderingManager::_drawTriangle(Vector3<T> v,
                                     Vector3<unsigned> color)
{
    _logger->log(DEBUG, "Rendering triangle: ", v);
    _drawLine(Vector2<T>(v[0], v[1]),
              Vector2<T>(v[1], v[2]),
              color);
    _drawLine(Vector2<T>(v[1], v[2]),
              Vector2<T>(v[2], v[0]),
              color);
    _drawLine(Vector2<T>(v[2], v[0]),
              Vector2<T>(v[0], v[1]),
              color);
}

/*
 *  Implements Bresenham's line algorithm
 *
 *  @param 'a' templatized Vector2 representing our first pixel's position
 *  @param 'b' templatized Vector2 representing our second pixel's position
 *  @return void
 */
template <typename T>    
void RenderingManager::_drawLine(Vector2<T> a,
                                 Vector2<T> b,
                                 Vector3<unsigned> color)
{
    // Calculate the absolute difference between the start and end points
    int absoluteXDifference = abs(b[0] - a[0]);
    int absoluteYDifference = abs(b[1] - a[1]);
    
    // Determine the direction of the line in the x and y dimensions
    int xStepValue = (a[0] < b[0]) ? 1 : -1;
    int yStepValue = (a[1] < b[1]) ? 1 : -1;
    
    // Initialize the error term
    int err = absoluteXDifference - absoluteYDifference;

    // Loop until line is drawn
    while (true)
    {
        // Draw a pixel at current position
        _drawPixel(a[0], a[1], color);

        // If we;ve reached the end point, break out of the loop
        if (a[0] == b[0] && a[1] == b[1])
        {
            break;
        }

        // Calculate twice the error term
        int errorAdjust = 2 * err;

        // If our error term is less than the y distance, adjust y coordinate
        if (errorAdjust > -absoluteYDifference)
        {
            err -= absoluteYDifference;
            a[0] += xStepValue;
        }
        
        // If our error term is less than the y distance, adjust x coordinate
        if (errorAdjust < absoluteXDifference)
        {
            err += absoluteXDifference;
            a[1] += yStepValue;
        }
    }
}
