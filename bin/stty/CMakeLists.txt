cmake_minimum_required(VERSION 3.0)  # CMake version check
project(stty)                     # Create project
set(C_STANDARD 1)                    # Set C11 standard

add_executable(stty cchar.c gfmt.c key.c modes.c print.c stty.c)
