cmake_minimum_required(VERSION 3.0)  # CMake version check
project(ksh)                     # Create project
set(C_STANDARD 1)                    # Set C11 standard

add_executable(sh alloc.c c_ksh.c c_sh.c c_ulimit.c edit.c emacs.c eval.c exec.c expr.c history.c io.c jobs.c lex.c mail.c main.c misc.c path.c shf.c syn.c table.c trap.c tty.c var.c version.c vi.c)
