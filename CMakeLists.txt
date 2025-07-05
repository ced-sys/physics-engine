cmake_minimum_required(VERSION 3.10)
project(PhysicsEngine)

set(CMAKE_CXX_STANDARD 17)

add_executable(physics-engine
	src/main.cpp
	src/vector2.cpp
	src/rigidbody.cpp
)

#Find SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

#SDL2/OpenGL visual version
add_executable(visual-physics
	src/main_sdl.cpp
	src/visualizer.cpp
	src/vector2.cpp
	src/rigidbody.cpp
)

target_link_libraries(visual-physics SDL2 SDL2main)

