{
    depfiles = "spectator.o: src/spectator/spectator.cpp include/spectator/spectator.h  include/camera/camera.h include/InputManager/inputManager.h\
",
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
    depfiles_format = "gcc",
    files = {
        "src/spectator/spectator.cpp"
    }
}