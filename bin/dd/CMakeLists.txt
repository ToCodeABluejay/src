cmake_minimum_required(VERSION 3.0)  # CMake version check
project(df)                     # Create project
set(C_STANDARD 1)                    # Set C11 standard

add_executable(df df.c ext2fs_df.c ffs_df.c)
