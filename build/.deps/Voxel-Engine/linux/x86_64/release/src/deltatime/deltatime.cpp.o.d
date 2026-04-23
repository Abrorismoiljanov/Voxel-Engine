{
    depfiles = "deltatime.o: src/deltatime/deltatime.cpp include/deltatime/deltatime.h\
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
        "src/deltatime/deltatime.cpp"
    }
}