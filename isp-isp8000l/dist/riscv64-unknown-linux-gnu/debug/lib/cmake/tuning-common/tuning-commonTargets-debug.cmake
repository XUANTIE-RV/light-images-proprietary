#----------------------------------------------------------------
# Generated CMake target import file for configuration "debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "tuning::tuning-common" for configuration "debug"
set_property(TARGET tuning::tuning-common APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(tuning::tuning-common PROPERTIES
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "jsoncpp_lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libtuning-common.so.5.0.0"
  IMPORTED_SONAME_DEBUG "libtuning-common.so.5"
  )

list(APPEND _IMPORT_CHECK_TARGETS tuning::tuning-common )
list(APPEND _IMPORT_CHECK_FILES_FOR_tuning::tuning-common "${_IMPORT_PREFIX}/lib/libtuning-common.so.5.0.0" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
