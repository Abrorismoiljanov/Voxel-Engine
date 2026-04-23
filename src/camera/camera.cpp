#include "camera/camera.h"

void camera::UpdateVectors(){
 
    glm::vec3 newFront;
    newFront.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    newFront.y = sin(glm::radians(pitch));
    newFront.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    front = glm::normalize(newFront);
    
    right = glm::normalize(glm::cross(front, glm::vec3(0.0f, 1.0f, 0.0f)));
    up = glm::normalize(glm::cross(right, front));
};


glm::mat4 camera::GetViewMatrix() {
    return glm::lookAt(position, position + front, up);
}

glm::mat4 camera::GetProjectionMatrix(int screenW, int screenH) {
    float aspect = (float)screenW / (float)screenH;
    return glm::perspective(glm::radians(fov), aspect, nearPlane, farPlane);
}

glm::vec3 camera::GetFront(){
    return front;
}
 
glm::vec3 camera::GetRight(){
    return right;
}


void camera::SetPosition(glm::vec3 pos){
    position = pos;
};
void camera::SetRotation(float newYaw, float newPitch){
    this->yaw = newYaw;
    this->pitch = newPitch;
    UpdateVectors();
}
