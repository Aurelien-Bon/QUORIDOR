cmake_minimum_required(VERSION 3.20)
project(QUORIDOR C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(QUORIDOR
        bariere.c
        bariere.h
        crosshaire.c
        crosshaire.h
        jeu.c
        jeu.h
        joueur.c
        joueur.h
        main.c
        terrain.c
        terrain.h)
