#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/trigonometric.hpp>
#include <glm/gtc/type_ptr.hpp> 

class camera{
private:
    glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 front = glm::vec3(0.0f, 0.0f, -1.0f);  
    glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
    glm::vec3 right;
 
    float yaw = -90.0f;
    float pitch = 0.0f;
    
    float fov = 75.0f;
    float nearPlane = 0.1f;
    float farPlane = 1000.0f;

    void UpdateVectors();

public:
    glm::mat4 GetViewMatrix();      
    glm::mat4 GetProjectionMatrix(int screenW, int screenH);  


    glm::vec3 GetFront();
    glm::vec3 GetRight();

    void SetPosition(glm::vec3 pos);
    void SetRotation(float yaw, float pitch);  
    
};
