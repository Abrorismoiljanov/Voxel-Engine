#include "SDL2/SDL.h"
#include "iostream"
#include "GL/glew.h"

#include "renderer/renderer.h"
#include "spectator/spectator.h"
#include "deltatime/deltatime.h"
#include "world/world/world.h"

class Game{
private:
    SDL_Window* window = nullptr;
    SDL_GLContext glContext = nullptr;
    int WinWidth = 800;
    int WinHeight = 600;

    Spectator Ghost;
    World world;
    Renderer renderer;
    InputManager input;
    Deltatime timer;

    bool running = true;
public:
    void Init();
    void Run();
};
