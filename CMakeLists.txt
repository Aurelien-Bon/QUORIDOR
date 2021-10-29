cmake_minimum_required(VERSION 3.20)
project(QUORIDOR C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(QUORIDOR
        main.c
        terrain.c
        terrain.h)
