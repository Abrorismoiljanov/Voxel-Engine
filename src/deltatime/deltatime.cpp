#include "deltatime/deltatime.h"

Deltatime::Deltatime(){
    lastTime = SDL_GetPerformanceCounter();
    deltatime = 0.0f;
};

void Deltatime::Update(){
    float currentTime = SDL_GetPerformanceCounter(); 
    deltatime = (currentTime - lastTime) / (float)SDL_GetPerformanceFrequency();

    lastTime = currentTime;

    if (deltatime > 0.1f) deltatime = 0.01f;
}

float Deltatime::GetDelta() const{
    return deltatime;
}

float Deltatime::GetFPS() const {
    if (deltatime > 0.0f) return 1.0f / deltatime;
    return 0.0f;
}
