#include "glm/glm.hpp"
#include "SDL.h"

#include "camera/camera.h"
#include "InputManager/inputManager.h"

class Spectator {
private:
    glm::vec3 position = glm::vec3(0.0f, 0.0f, 3.0f);
    float yaw = -90.0f;
    float pitch = 0.0f;
    float moveSpeed = 5.0f;
    float lookSensitivity = 0.4f;
    
    
public:
    
    void Update(float deltaTime, InputManager& input);
   
    void ProcessKeyboard(int direction, float deltaTime);  
    
    void ProcessMouse(float xOffset, float yOffset);       
    
    camera Camera;  

private:
    void UpdateCamera();
};
