cmake_minimum_required(VERSION 3.0)  # CMake version check
project(echo)                     # Create project
set(C_STANDARD 1)                    # Set C11 standard

add_executable(echo echo.c)
