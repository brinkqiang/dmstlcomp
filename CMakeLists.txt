cmake_minimum_required(VERSION 3.2)

PROJECT(dmstlcomp)

LIST(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
INCLUDE(cmake/ModuleImport.cmake)
INCLUDE(cmake/ModuleCompileOptions.cmake)
ModuleSetCompileOptions()
ModuleSetWinCompilerFlags()

SET(DMSTLCOMP_VERSION_MAJOR "1")
SET(DMSTLCOMP_VERSION_MINOR "0")
SET(DMSTLCOMP_VERSION_PATCH "1")
SET(DMSTLCOMP_VERSION "${DMSTLCOMP_VERSION_MAJOR}.${DMSTLCOMP_VERSION_MINOR}.${DMSTLCOMP_VERSION_PATCH}")

MESSAGE(STATUS "VERSION: ${DMSTLCOMP_VERSION}")

OPTION(USE_DMSTLCOMP "use dmstlcomp" OFF)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/include/dmstlcomp_config.h.in ${CMAKE_CURRENT_SOURCE_DIR}/include/dmstlcomp_config.h)

ModuleImportAll("thirdparty")
LibImport("dmstlcomp_module" "src/dmstlcomp_module")
ExeImport("test" "dmstlcomp_module")

#ADD_CUSTOM_COMMAND(
#TARGET dmstlcomptest
#PRE_BUILD
#COMMAND ${CMAKE_COMMAND} -E copy_if_different
#${CMAKE_CURRENT_SOURCE_DIR}/config/test.csv
#$<TARGET_FILE_DIR:dmstlcomptest>
#)

#INSTALL(DIRECTORY include/ DESTINATION include)
#INSTALL(TARGETS dmstlcomp
#        RUNTIME DESTINATION bin
#        LIBRARY DESTINATION lib
#        ARCHIVE DESTINATION lib)

#SET(DMSTLCOMP_LIBS "dmstlcomp")
#MARK_AS_ADVANCED(${DMSTLCOMP_LIBS})