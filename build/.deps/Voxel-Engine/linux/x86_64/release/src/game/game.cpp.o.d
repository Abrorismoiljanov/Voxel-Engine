{
    values = {
        "/usr/bin/g++",
        {
            "-m64",
            "-fvisibility=hidden",
            "-fvisibility-inlines-hidden",
            "-O3",
            "-I.",
            "-Iinclude",
            "-D_GNU_SOURCE=1",
            "-D_REENTRANT",
            "-isystem",
            "/usr/include/SDL2",
            "-DNDEBUG"
        }
    },
    files = {
        "src/game/game.cpp"
    },
    depfiles = "game.o: src/game/game.cpp include/game/game.h include/renderer/renderer.h  include/world/chunk/chunk.h include/spectator/spectator.h  include/camera/camera.h include/InputManager/inputManager.h  include/deltatime/deltatime.h include/world/world/world.h\
",
    depfiles_format = "gcc"
}