cmake_minimum_required(VERSION 3.0)  # CMake version check
project(bsd.arm64)                   # Create project
set(C_STANDARD 1)                    # Set C11 standard

target_include_directories(sys
                            public
                            ../../../sys/
                            )

# Add all the files needed for compilation

add_executable(bsd.arm64 acpi_machdep.c acpiapm.c aesv8-armx.S ast.c autoconf.c bus_dma.c conf.c copy.S copystr.S cpu.c cpufunc_asm.S cpuswitch.S cryptoc.c db_disasm.c db_interface.c db_trace.c disasm.c disksubr.c exception.S fpu.c intr.c locore0.S machdep.c mem.c openprom.c pmap.c process_machdep.c sig_machdep.c softintr.c support.S sys_machdep.c syscall.c trampoline.S trap.c vm_machdep.c)
