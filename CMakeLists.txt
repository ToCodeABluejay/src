cmake_minimum_required(VERSION 3.0)  # CMake version check
project(bsdbase)               # Create project
set(C_STANDARD 1)            # Set C11 standard

# Be sure to include the needed subriectories
add_subdirectory(bin)
add_subdirectory(distrub)
add_subdirectory(etc)
add_subdirectory(games)
add_subdirectory(gnu)
add_subdirectory(include)
add_subdirectory(lib)
add_subdirectory(libexec)
add_subdirectory(regress)
add_subdirectory(sbin)
add_subdirectory(share)
add_subdirectory(sys)
add_subdirectory(usr.bin)
add_subdirectory(usr.sbin)

