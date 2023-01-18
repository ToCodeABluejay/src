cmake_minimum_required(VERSION 3.0)  # CMake version check
project(bsdbase)                     # Create project
set(C_STANDARD 1)                    # Set C11 standard

# Be sure to include the needed subriectories
add_subdirectory(amd)
add_subdirectory(etc.alpha)
add_subdirectory(etc.amd64)
add_subdirectory(etc.armv7)
add_subdirectory(etc.hppa)
add_subdirectory(etc.i386)
add_subdirectory(etc.landisk)
add_subdirectory(etc.loongson)
add_subdirectory(etc.luna86k)
add_subdirectory(etc.macppc)
add_subdirectory(etc.octeon)
add_subdirectory(etc.powerpc64)
add_subdirectory(etc.riscv64)
add_subdirectory(etc.sparc64)
add_subdirectory(examples)
add_subdirectory(mail)
add_subdirectory(mtree)
add_subdirectory(ppp)
add_subdirectory(rc.d)
add_subdirectory(root)
add_subdirectory(rpki)
add_subdirectory(signify)
add_subdirectory(skel)
