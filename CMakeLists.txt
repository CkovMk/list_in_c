cmake_minimum_required(VERSION 3.14)
project(List C)

set(CMAKE_C_STANDARD 99)

add_executable(List main.c list_cycle.c list_cycle.h list.c list.h)