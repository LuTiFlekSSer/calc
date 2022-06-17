cmake_minimum_required(VERSION 3.21)
project(project1 C)

set(CMAKE_C_STANDARD 99)
MATH(EXPR stack_size "100 * 1024 * 1024")
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack,${stack_size}")

add_executable(project1 main.c solve.c solve.h struct.h pars.c pars.h)
