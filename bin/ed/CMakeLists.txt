cmake_minimum_required(VERSION 3.0)  # CMake version check
project(ed)                     # Create project
set(C_STANDARD 1)                    # Set C11 standard

add_executable(ed buf.c glbl.c io.c main.c re.c sub.c undo.c)
