cmake_minimum_required(VERSION 3.27)
project(Tetris_Clone)

set(CMAKE_CXX_STANDARD 23)

set(SDL2_INCLUDE_DIR C:/SDL/include)
set(SDL2_LIB_DIR C:/SDL/lib/x64)

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})

add_executable(Tetris_Clone Main.cpp
        pieces.h
        pieces.cpp
        board.cpp
        board.h
        board.h)

target_link_libraries(${PROJECT_NAME} SDL2main SDL2)

