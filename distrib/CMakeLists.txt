cmake_minimum_required(VERSION 3.0)  # CMake version check
project(distrib)                     # Create project
set(C_STANDARD 1)                    # Set C11 standard

# Be sure to include the needed subriectories
add_subdirectory(alpha)
add_subdirectory(amd64)
add_subdirectory(arm64)
add_subdirectory(armv7)
add_subdirectory(hppa)
add_subdirectory(i386)
add_subdirectory(landisk)
add_subdirectory(loongson)
add_subdirectory(luna86k)
add_subdirectory(macppc)
add_subdirectory(miniroot)
add_subdirectory(notes)
add_subdirectory(octeon)
add_subdirectory(powerpc64)
add_subdirectory(riscv74)
add_subdirectory(sets)
add_subdirectory(sparc64)
add_subdirectory(special)
add_subdirectory(syspatch)
