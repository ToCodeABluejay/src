cmake_minimum_required(VERSION 3.0)  # CMake version check
project(ufs)                     # Create project
set(C_STANDARD 1)                    # Set C11 standard

# Be sure to include the needed subriectories
add_subdirectory(ext2fs)
add_subdirectory(ffs)
add_subdirectory(mfs)
add_subdirectory(ufs)
