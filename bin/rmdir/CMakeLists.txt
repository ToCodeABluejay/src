cmake_minimum_required(VERSION 3.0)  # CMake version check
project(rmdir)                     # Create project
set(C_STANDARD 1)                    # Set C11 standard

add_executable(rmdir rmdir.c)
