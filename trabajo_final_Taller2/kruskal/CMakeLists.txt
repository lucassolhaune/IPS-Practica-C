cmake_minimum_required(VERSION 3.22)
project(kruskal C)

set(CMAKE_C_STANDARD 99)

add_executable(kruskal main.c lib/library.c lib/library.h)
