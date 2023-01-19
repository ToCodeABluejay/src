cmake_minimum_required(VERSION 3.0)  # CMake version check
project(mv)                     # Create project
set(C_STANDARD 1)                    # Set C11 standard

add_executable(cp cp.c mv.c rm.c)
