cmake_minimum_required(VERSION 3.0)  # CMake version check
project(conf)                     # Create project
set(C_STANDARD 1)                    # Set C11 standard

# Be sure to include the needed subriectories
add_executable(param.o param.c)
add_executable(swapgeneric.o swapgeneric.c)
