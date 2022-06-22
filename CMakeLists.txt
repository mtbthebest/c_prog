cmake_minimum_required(VERSION 3.16)
project(c_prog C)

set(CMAKE_C_STANDARD 99)

add_executable(c_prog main.c)
add_executable(t1 tutorials/t1.c)
add_executable(t2 tutorials/t2.c)
add_executable(t3 tutorials/t3.c)