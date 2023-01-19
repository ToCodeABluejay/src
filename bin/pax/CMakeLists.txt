cmake_minimum_required(VERSION 3.0)  # CMake version check
project(pax)                     # Create project
set(C_STANDARD 1)                    # Set C11 standard

add_executable(pax ar_io.c ar_subs.c cpio.c file_subs.c ftree.c gen_subs.c getoldopt.c options.c pat_rep.c pax.c sel_subs.c tables.c tar.c tty_subs.c)
