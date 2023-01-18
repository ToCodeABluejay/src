cmake_minimum_required(VERSION 3.0)  # CMake version check
project(system)                     # Create project
set(C_STANDARD 1)                    # Set C11 standard

# Be sure to include the needed subriectories
add_subdirectory(arch)
add_subdirectory(conf)
add_subdirectory(crypto)
add_subdirectory(ddb)
add_subdirectory(dev)
add_subdirectory(isofs)
add_subdirectory(kern)
add_subdirectory(lib)
add_subdirectory(miscfs)
add_subdirectory(msdosfs)
add_subdirectory(net)
add_subdirectory(net80211)
add_subdirectory(netinet)
add_subdirectory(netinet6)
add_subdirectory(netmpls)
add_subdirectory(nfs)
add_subdirectory(ntfs)
add_subdirectory(scsi)
add_subdirectory(stand)
add_subdirectory(sys)
add_subdirectory(tmpfs)
add_subdirectory(ufs)
add_subdirectory(uvm)
