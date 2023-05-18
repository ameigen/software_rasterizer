#pragma once
#include<SDL2/SDL.h>

struct Texture
{
    private:
        unsigned width;
        unsigned height;
        SDL_Surface* surface;
        SDL_Texture* texture;

        Texture(unsigned x, unsigned y) : width(x), height(y) {}
    public:
};