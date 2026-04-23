set_project("Voxel-Engine")
set_version("0.1.0")

add_rules("mode.debug", "mode.release")

add_requires("imgui", "sdl2", "glew")

target("Voxel-Engine")
 
set_kind("binary")

add_files("./src/**.cpp")

add_packages("imgui", "sdl2", "glew")

add_includedirs(
    ".",
    "./include"
)

