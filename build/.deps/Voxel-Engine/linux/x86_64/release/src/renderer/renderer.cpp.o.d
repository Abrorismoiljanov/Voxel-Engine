{
    depfiles_format = "gcc",
    files = {
        "src/renderer/renderer.cpp"
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
    },
    depfiles = "renderer.o: src/renderer/renderer.cpp include/renderer/renderer.h  include/world/chunk/chunk.h\
"
}