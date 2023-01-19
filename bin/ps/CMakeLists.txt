cmake_minimum_required(VERSION 3.0)  # CMake version check
project(ps)                     # Create project
set(C_STANDARD 1)                    # Set C11 standard

add_executable(ps keyword.c nlist.c print.c ps.c utf8.c)
