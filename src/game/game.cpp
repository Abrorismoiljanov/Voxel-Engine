#include "game/game.h"

void Game::Init(){

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
 

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "SDL Init error"<< '\n';
    }

    window = SDL_CreateWindow("Voxel Game", 
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              WinWidth, WinHeight,
                              SDL_WINDOW_OPENGL);

    if (!window) {
        std::cout << "Window creation error"<< '\n';
    }

    glContext = SDL_GL_CreateContext(window);
    if (!glContext) {
        std::cout << "Context creation error"<< '\n';
    }


    if (glewInit() != GLEW_OK) {
        std::cout << "Glew Init error"<< '\n';
    }
    glEnable(GL_DEPTH_TEST);

 
    SDL_SetRelativeMouseMode(SDL_TRUE);
    world.chunk.generate();
    renderer.Init();
    glViewport(0, 0, WinWidth, WinHeight);
};

void Game::Run(){
 
    while (running) {
        
        timer.Update();


        input.Update();
        if (input.CloseRequest()) {
            running = false;
        }

        Ghost.Update(timer.GetDelta(), input);

        std::cout << "\033[2J\033[1;1H"; 
        renderer.Clear();
        std::cout << "FPS:" << timer.GetFPS() << '\n';
 
        glm::mat4 view = Ghost.Camera.GetViewMatrix();
        glm::mat4 proj = Ghost.Camera.GetProjectionMatrix(WinWidth, WinHeight);
        renderer.RenderChunk(world.chunk ,view, proj);

    
        SDL_GL_SwapWindow(window);
    }

    SDL_Quit();
}

