# Install script for directory: /home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/tinyxml2

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

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xtinyxml2_librariesx" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libtinyxml2d.so.8.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libtinyxml2d.so.8"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/tinyxml2/libtinyxml2d.so.8.0.0"
    "/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/tinyxml2/libtinyxml2d.so.8"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libtinyxml2d.so.8.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libtinyxml2d.so.8"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/recipe-sysroot-native/usr/bin/riscv64-oe-linux/riscv64-linux-strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xtinyxml2_librariesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libtinyxml2d.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libtinyxml2d.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libtinyxml2d.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/tinyxml2/libtinyxml2d.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libtinyxml2d.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libtinyxml2d.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/recipe-sysroot-native/usr/bin/riscv64-oe-linux/riscv64-linux-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libtinyxml2d.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xtinyxml2_headersx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES "/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/tinyxml2/tinyxml2.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xtinyxml2_configx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/tinyxml2/tinyxml2.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xtinyxml2_configx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/tinyxml2" TYPE FILE FILES
    "/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/tinyxml2/tinyxml2Config.cmake"
    "/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/tinyxml2/tinyxml2ConfigVersion.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xtinyxml2_configx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/tinyxml2/tinyxml2Targets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/tinyxml2/tinyxml2Targets.cmake"
         "/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/tinyxml2/CMakeFiles/Export/lib/cmake/tinyxml2/tinyxml2Targets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/tinyxml2/tinyxml2Targets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/tinyxml2/tinyxml2Targets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/tinyxml2" TYPE FILE FILES "/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/tinyxml2/CMakeFiles/Export/lib/cmake/tinyxml2/tinyxml2Targets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/tinyxml2" TYPE FILE FILES "/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/tinyxml2/CMakeFiles/Export/lib/cmake/tinyxml2/tinyxml2Targets-debug.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/jianghm.bsp/bsp_1_1_8/thead-build/light-fm/tmp-glibc/work/riscv64-oe-linux/isp-isp8000l/1.0-r0/git/build/riscv64-unknown-linux-gnu/debug/tinyxml2/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
