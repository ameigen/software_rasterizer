#include "InputManager.h"

void InputManager::handleEvent(const SDL_Event& event) 
{
    if (event.type == SDL_KEYDOWN) 
    {
        m_keyStates[event.key.keysym.scancode] = true;
    } 
    else if (event.type == SDL_KEYUP) 
    {
        m_keyStates[event.key.keysym.scancode] = false;
    } 
    else if (event.type == SDL_MOUSEBUTTONDOWN) 
    {
        m_mouseButtonStates[event.button.button] = true;
    } 
    else if (event.type == SDL_MOUSEBUTTONUP) 
    {
        m_mouseButtonStates[event.button.button] = false;
    } 
    else if (event.type == SDL_MOUSEMOTION) 
    {
        m_mouseX = event.motion.x;
        m_mouseY = event.motion.y;
    }
}

bool InputManager::isKeyDown(SDL_Scancode key) const 
{
    return m_keyStates[key];
}

bool InputManager::isKeyUp(SDL_Scancode key) const 
{
    return !isKeyDown(key);
}

bool InputManager::isMouseButtonDown(Uint8 button) const 
{
    return m_mouseButtonStates[button];
}

bool InputManager::isMouseButtonUp(Uint8 button) const 
{
    return !isMouseButtonDown(button);
}

std::pair<int, int> InputManager::getMousePosition() const 
{
    return std::make_pair(m_mouseX, m_mouseY);
}