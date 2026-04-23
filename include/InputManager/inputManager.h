#include "SDL.h"
#include "glm/glm.hpp"
#include "string"

class InputManager {
public:
    void Update();
    
    bool IsKeyPressed(SDL_Scancode key) const;
    bool IsKeyReleased(SDL_Scancode key) const;
    bool IsKeyHeld(SDL_Scancode key) const;
    
    glm::vec2 GetMouseDelta() const;    
    
    bool IsMouseButtonPressed(Uint8 button) const;
    
    bool IsMouseButtonReleased(Uint8 button) const;
    
    bool IsMouseButtonHeld(Uint8 button) const;
    
    glm::vec2 GetMousePosition() const;     
    
    bool CloseRequest();

    float GetScrollDelta() const;
    
    std::string GetTextInput() const;
    
private:

    bool Closerequest = false;
    std::array<bool, SDL_NUM_SCANCODES> currentKeys{};
    std::array<bool, SDL_NUM_SCANCODES> previousKeys{};
    
    glm::vec2 mouseDelta{0.0f, 0.0f};
    glm::vec2 mousePosition{0.0f, 0.0f};
    std::array<bool, 5> mouseButtons{};  
    std::array<bool, 5> prevMouseButtons{};
    
    float scrollDelta{0.0f};
    std::string textInput{};
};
