# Install script for directory: /home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/units

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
  include("/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/appshell/obj/units/obj/ebase/cmake_install.cmake")
  include("/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/appshell/obj/units/obj/oslayer/cmake_install.cmake")
  include("/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/appshell/obj/units/obj/version/cmake_install.cmake")
  include("/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/appshell/obj/units/obj/fpga/cmake_install.cmake")
  include("/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/appshell/obj/units/obj/i2c_drv/cmake_install.cmake")
  include("/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/appshell/obj/units/obj/hal/cmake_install.cmake")
  include("/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/appshell/obj/units/obj/scmi/cmake_install.cmake")
  include("/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/appshell/obj/units/obj/common/cmake_install.cmake")
  include("/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/appshell/obj/units/obj/bufferpool/cmake_install.cmake")
  include("/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/appshell/obj/units/obj/vom_ctrl/cmake_install.cmake")
  include("/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/appshell/obj/units/obj/som_ctrl/cmake_install.cmake")
  include("/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/appshell/obj/units/obj/ibd/cmake_install.cmake")
  include("/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/appshell/obj/units/obj/bufsync_ctrl/cmake_install.cmake")
  include("/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/appshell/obj/units/obj/cameric_reg_drv/cmake_install.cmake")
  include("/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/appshell/obj/units/obj/cameric_drv/cmake_install.cmake")
  include("/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/appshell/obj/units/obj/mipi_drv/cmake_install.cmake")
  include("/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/appshell/obj/units/obj/isi/cmake_install.cmake")
  include("/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/appshell/obj/units/obj/cam_calibdb/cmake_install.cmake")
  include("/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/appshell/obj/units/obj/aaa/cmake_install.cmake")
  include("/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/appshell/obj/units/obj/3av2/cmake_install.cmake")
  include("/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/appshell/obj/units/obj/mim_ctrl/cmake_install.cmake")
  include("/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/appshell/obj/units/obj/mom_ctrl/cmake_install.cmake")
  include("/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/appshell/obj/units/obj/cim_ctrl/cmake_install.cmake")
  include("/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/appshell/obj/units/obj/cam_engine/cmake_install.cmake")
  include("/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/appshell/obj/units/obj/cam_device/cmake_install.cmake")
  include("/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/appshell/obj/units/obj/test/cmake_install.cmake")

endif()

