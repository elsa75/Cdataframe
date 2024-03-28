cmake_minimum_required(VERSION 3.27)
project(Cdataframe C)

set(CMAKE_C_STANDARD 11)

add_executable(Cdataframe main.c
        fonctions.c
        fonctions.h
        nathan_test.c)
