cmake_minimum_required(VERSION 3.10)
project(PhysicsEngine)

set(CMAKE_CXX_STANDARD 17)

# Find SDL2
find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL2 REQUIRED sdl2)

# Console version
add_executable(physics-engine
	src/main.cpp
	src/vector2.cpp
	src/rigidbody.cpp
)

# Visual version with SDL2
add_executable(visual-physics
	src/main_sdl.cpp
	src/vector2.cpp
	src/rigidbody.cpp
	src/visualizer.cpp
)

# Link SDL2 to the visual version
target_link_libraries(visual-physics ${SDL2_LIBRARIES})
target_include_directories(visual-physics PRIVATE ${SDL2_INCLUDE_DIRS})
target_compile_options(visual-physics PRIVATE ${SDL2_CFLAGS_OTHER})