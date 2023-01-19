cmake_minimum_required(VERSION 3.0)  # CMake version check
project(test)                     # Create project
set(C_STANDARD 1)                    # Set C11 standard

add_executable(test test.c)
