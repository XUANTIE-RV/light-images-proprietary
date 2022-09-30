#----------------------------------------------------------------
# Generated CMake target import file for configuration "debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "cppnetlib-uri" for configuration "debug"
set_property(TARGET cppnetlib-uri APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(cppnetlib-uri PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/dist/riscv64-unknown-linux-gnu/debug/lib/libcppnetlib-uri.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS cppnetlib-uri )
list(APPEND _IMPORT_CHECK_FILES_FOR_cppnetlib-uri "/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/dist/riscv64-unknown-linux-gnu/debug/lib/libcppnetlib-uri.a" )

# Import target "cppnetlib-server-parsers" for configuration "debug"
set_property(TARGET cppnetlib-server-parsers APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(cppnetlib-server-parsers PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/dist/riscv64-unknown-linux-gnu/debug/lib/libcppnetlib-server-parsers.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS cppnetlib-server-parsers )
list(APPEND _IMPORT_CHECK_FILES_FOR_cppnetlib-server-parsers "/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/dist/riscv64-unknown-linux-gnu/debug/lib/libcppnetlib-server-parsers.a" )

# Import target "cppnetlib-client-connections" for configuration "debug"
set_property(TARGET cppnetlib-client-connections APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(cppnetlib-client-connections PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "Boost::system;Boost::thread;-lpthread"
  IMPORTED_LOCATION_DEBUG "/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/dist/riscv64-unknown-linux-gnu/debug/lib/libcppnetlib-client-connections.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS cppnetlib-client-connections )
list(APPEND _IMPORT_CHECK_FILES_FOR_cppnetlib-client-connections "/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/dist/riscv64-unknown-linux-gnu/debug/lib/libcppnetlib-client-connections.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
