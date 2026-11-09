cmake_minimum_required(VERSION 3.15)

project(TetrisGame CXX)

set(CMAKE_C_STANDARD 99)

find_package(raylib REQUIRED)

add_executable(TetrisGame main.cpp grid.cpp colors.cpp position.cpp block.cpp game.cpp)

target_link_libraries(TetrisGame raylib)
