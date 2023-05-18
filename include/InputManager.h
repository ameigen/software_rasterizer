#pragma once

#include <SDL2/SDL.h>
#include <array>
#include <iostream>

class InputManager {
public:
    void handleEvent(const SDL_Event& event);

    bool isKeyDown(SDL_Scancode key) const;
    bool isKeyUp(SDL_Scancode key) const;
    bool isMouseButtonDown(Uint8 button) const;
    bool isMouseButtonUp(Uint8 button) const;
    std::pair<int, int> getMousePosition() const;

private:
    std::array<bool, SDL_NUM_SCANCODES> m_keyStates{};
    std::array<bool, 8> m_mouseButtonStates{}; // SDL supports up to 8 mouse buttons
    int m_mouseX;
    int m_mouseY;
};