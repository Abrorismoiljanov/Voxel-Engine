{
    depfiles_format = "gcc",
    depfiles = "camera.o: src/camera/camera.cpp include/camera/camera.h\
",
    files = {
        "src/camera/camera.cpp"
    },
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
    }
}