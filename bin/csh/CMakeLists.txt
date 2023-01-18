cmake_minimum_required(VERSION 3.0)  # CMake version check
project(csh)                     # Create project
set(C_STANDARD 1)                    # Set C11 standard

add_executable(cp alloc.c char.c const.c csh.c dir.c dol.c error.c exec.c exp.c file.c func.c glob.c hist.c init.c lex.c misc.c parse.c proc.c sem.c set.c str.c time.c)

#USD.doc - what to do?
