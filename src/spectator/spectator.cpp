#include "spectator/spectator.h"


void Spectator::Update(float deltaTime, InputManager& input){
    glm::vec3 moveDir(0.0f);
    if (input.IsKeyHeld(SDL_SCANCODE_W)) moveDir += Camera.GetFront();
    if (input.IsKeyHeld(SDL_SCANCODE_S)) moveDir -= Camera.GetFront();
    if (input.IsKeyHeld(SDL_SCANCODE_A)) moveDir -= Camera.GetRight();
    if (input.IsKeyHeld(SDL_SCANCODE_D)) moveDir += Camera.GetRight();
    if (input.IsKeyHeld(SDL_SCANCODE_Q)) moveDir += glm::vec3(0.0f, 1.0f, 0.0f);  
    if (input.IsKeyHeld(SDL_SCANCODE_E)) moveDir -= glm::vec3(0.0f, 1.0f, 0.0f);
    
    position += moveDir * moveSpeed * deltaTime;
    

    glm::vec2 mouseDelta = input.GetMouseDelta();
    yaw += mouseDelta.x * lookSensitivity;
    pitch -= mouseDelta.y * lookSensitivity;
    pitch = glm::clamp(pitch, -89.0f, 89.0f);
    
    Camera.SetPosition(position);
    Camera.SetRotation(yaw, pitch);  
}
