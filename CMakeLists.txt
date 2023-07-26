cmake_minimum_required(VERSION 3.7)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(SDL2_Fractal)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} src include)

add_executable(JuliaSet src/main.cpp src/julia.cpp src/renderer.cpp src/parameters.cpp)
string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
target_link_libraries(JuliaSet ${SDL2_LIBRARIES})
