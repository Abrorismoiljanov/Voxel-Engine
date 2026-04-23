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
    depfiles_format = "gcc",
    depfiles = "inputManager.o: src/inputManager/inputManager.cpp  include/InputManager/inputManager.h\
",
    files = {
        "src/inputManager/inputManager.cpp"
    }
}