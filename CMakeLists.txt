cmake_minimum_required(VERSION 3.27)
project(Block_Game)

set(CMAKE_CXX_STANDARD 23)

set(SDL2_INCLUDE_DIR C:/SDL/include)
set(SDL2_LIB_DIR C:/SDL/lib/x64)

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})

add_executable(Block_Game Main.cpp
        pieces.h
        pieces.cpp
        board.cpp
        board.h
        board.h
        game.cpp
        game.h
        IO.cpp
        IO.h)

target_link_libraries(${PROJECT_NAME} SDL2main SDL2)

