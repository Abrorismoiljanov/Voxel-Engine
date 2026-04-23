#include "InputManager/inputManager.h"

void InputManager::Update() {
    previousKeys = currentKeys;
    prevMouseButtons = mouseButtons;
       
    mouseDelta = {0.0f, 0.0f};
    scrollDelta = 0.0f;
    textInput.clear();
       
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_KEYDOWN:
                currentKeys[event.key.keysym.scancode] = true;
                break;
            case SDL_KEYUP:
                currentKeys[event.key.keysym.scancode] = false;
                break;
            case SDL_MOUSEMOTION:
                mouseDelta.x = event.motion.xrel;
                mouseDelta.y = event.motion.yrel;
                mousePosition.x = event.motion.x;
                mousePosition.y = event.motion.y;
                break;
            case SDL_MOUSEBUTTONDOWN:
                mouseButtons[event.button.button] = true;
                break;
            case SDL_MOUSEBUTTONUP:
                mouseButtons[event.button.button] = false;
                break;
            case SDL_MOUSEWHEEL:
                scrollDelta = event.wheel.y;  
                break;
            case SDL_TEXTINPUT:
                textInput = event.text.text;
                break;
            case SDL_QUIT:
            Closerequest = true;
            break;
        }
    }
}
bool InputManager::CloseRequest(){
    return Closerequest;
}
bool InputManager::IsKeyPressed(SDL_Scancode key) const {
    return currentKeys[key] && !previousKeys[key];
}
bool InputManager::IsKeyReleased(SDL_Scancode key) const {
    return !currentKeys[key] && previousKeys[key];
}
bool InputManager::IsKeyHeld(SDL_Scancode key) const {
    return currentKeys[key];
}
glm::vec2 InputManager::GetMouseDelta() const {
    return mouseDelta;
}
bool InputManager::IsMouseButtonPressed(Uint8 button) const {
    return mouseButtons[button] && !prevMouseButtons[button];
}
bool InputManager::IsMouseButtonReleased(Uint8 button) const {
    return !mouseButtons[button] && prevMouseButtons[button];
}
bool InputManager::IsMouseButtonHeld(Uint8 button) const {
    return mouseButtons[button];
}
glm::vec2 InputManager::GetMousePosition() const {
    return mousePosition;
}
float InputManager::GetScrollDelta() const {
    return scrollDelta;
}
std::string InputManager::GetTextInput() const {
    return textInput;
}

