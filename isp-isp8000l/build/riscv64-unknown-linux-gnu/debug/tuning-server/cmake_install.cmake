# Install script for directory: /home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/tuning-server

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/dist/riscv64-unknown-linux-gnu/debug")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/recipe-sysroot-native/usr/bin/riscv64-oe-linux/riscv64-linux-objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/dist/riscv64-unknown-linux-gnu/debug/lib/libtuning-camera-old.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/dist/riscv64-unknown-linux-gnu/debug/lib/libtuning-camera-old.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/dist/riscv64-unknown-linux-gnu/debug/lib/libtuning-camera-old.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/dist/riscv64-unknown-linux-gnu/debug/lib/libtuning-camera-old.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/dist/riscv64-unknown-linux-gnu/debug/lib" TYPE SHARED_LIBRARY FILES "/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/tuning-server/libtuning-camera-old.so")
  if(EXISTS "$ENV{DESTDIR}/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/dist/riscv64-unknown-linux-gnu/debug/lib/libtuning-camera-old.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/dist/riscv64-unknown-linux-gnu/debug/lib/libtuning-camera-old.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/dist/riscv64-unknown-linux-gnu/debug/lib/libtuning-camera-old.so"
         OLD_RPATH "/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/tuning-server/../output/rootfs/bsp/dw200/lib:/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/tuning-server/../output/rootfs/bsp/isp/lib:/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/tuning-server/../output/rootfs/bsp/isp_ry/lib:/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/tuning-server/../vi_mem/output:/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/appshell/generated/debug/lib:/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/dw200/buffer.out:/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/dw200/fpga.out:/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/dw200/hal:/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/dist/riscv64-unknown-linux-gnu/debug/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/recipe-sysroot-native/usr/bin/riscv64-oe-linux/riscv64-linux-strip" "$ENV{DESTDIR}/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/dist/riscv64-unknown-linux-gnu/debug/lib/libtuning-camera-old.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/dist/riscv64-unknown-linux-gnu/debug/include/tuning-camera-old/")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/dist/riscv64-unknown-linux-gnu/debug/include/tuning-camera-old" TYPE DIRECTORY FILES "/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/tuning-server/include/")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/tuning-server/lite/cmake_install.cmake")
  include("/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/tuning-server/server/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/tuning-server/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
