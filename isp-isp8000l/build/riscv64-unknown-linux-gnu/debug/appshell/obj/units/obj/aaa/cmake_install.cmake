# Install script for directory: /home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/units/aaa

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

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/appshell/obj/units/obj/aaa/aec/cmake_install.cmake")
  include("/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/appshell/obj/units/obj/aaa/awb/cmake_install.cmake")
  include("/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/appshell/obj/units/obj/aaa/avs/cmake_install.cmake")
  include("/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/appshell/obj/units/obj/aaa/af/cmake_install.cmake")
  include("/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/appshell/obj/units/obj/aaa/adpf/cmake_install.cmake")
  include("/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/appshell/obj/units/obj/aaa/adpcc/cmake_install.cmake")
  include("/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/appshell/obj/units/obj/aaa/a2dnr/cmake_install.cmake")
  include("/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/appshell/obj/units/obj/aaa/a3dnr/cmake_install.cmake")
  include("/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/appshell/obj/units/obj/aaa/a2dnrv5/cmake_install.cmake")
  include("/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/appshell/obj/units/obj/aaa/atdnr/cmake_install.cmake")
  include("/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/appshell/obj/units/obj/aaa/awdr3/cmake_install.cmake")
  include("/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/appshell/obj/units/obj/aaa/awdr4/cmake_install.cmake")
  include("/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/appshell/obj/units/obj/aaa/ahdr/cmake_install.cmake")
  include("/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/appshell/obj/units/obj/aaa/aee/cmake_install.cmake")
  include("/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/appshell/obj/units/obj/aaa/aca/cmake_install.cmake")
  include("/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/appshell/obj/units/obj/aaa/adci/cmake_install.cmake")
  include("/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/appshell/obj/units/obj/aaa/aflt/cmake_install.cmake")

endif()

