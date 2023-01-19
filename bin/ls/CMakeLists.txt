cmake_minimum_required(VERSION 3.0)  # CMake version check
project(ls)                     # Create project
set(C_STANDARD 1)                    # Set C11 standard

add_executable(ls cmp.c ls.c main.c print.c utf8.c util.c)
