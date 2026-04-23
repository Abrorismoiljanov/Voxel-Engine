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
    depfiles = "chunk.o: src/world/chunk/chunk.cpp include/world/chunk/chunk.h\
",
    files = {
        "src/world/chunk/chunk.cpp"
    },
    depfiles_format = "gcc"
}