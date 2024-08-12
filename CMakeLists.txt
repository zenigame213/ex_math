cmake_minimum_required(VERSION 3.16)

#------------------------------------------------------------------------------

#Constant defines

#------------------------------------------------------------------------------
project("libmath"
    LANGUAGES C CXX
    DESCRIPTION "Example Math Library"
)
set(${PROJECT_NAME}_NAMESPACE "ex_math")
set(${PROJECT_NAME}_VERSION "1.0.0")

message(STATUS "${PROJECT_NAME}  Version: ${${PROJECT_NAME}_VERSION}")

#------------------------------------------------------------------------------

#Options

#------------------------------------------------------------------------------
option(WITH_UT "Build with unit test" OFF)
if (WITH_UT)
    add_definitions(-DWITH_UT)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
    set(COVERAGE_LIBRARIES "gcov")
endif ()

#------------------------------------------------------------------------------

#Dependencies

#------------------------------------------------------------------------------
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

#search for additional CMake modules

list(APPEND CMAKE_MODULE_PATH
${CMAKE_CURRENT_SOURCE_DIR}/cmake
${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules
)

find_package(libnn REQUIRED)

#------------------------------------------------------------------------------

#Sources

#------------------------------------------------------------------------------
set(${PROJECT_NAME}_PUBLIC_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/include/ex_math.hpp
)

set(${PROJECT_NAME}_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ex_math.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ex_calculator.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/nn_framework.cpp
)

#------------------------------------------------------------------------------

#Build targets

#------------------------------------------------------------------------------
add_library(
    ${PROJECT_NAME}
STATIC
    ${${PROJECT_NAME}_SOURCES}
)
target_include_directories(
    ${PROJECT_NAME}
PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${LIBNN_INCLUDE_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}>
)
target_link_libraries(${PROJECT_NAME}
    ${LIBNN_LIBRARY}
)
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")

#------------------------------------------------------------------------------

#Installation

#------------------------------------------------------------------------------
install(
TARGETS ${PROJECT_NAME}
EXPORT ${PROJECT_NAME}Targets
LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(
FILES ${${PROJECT_NAME}_PUBLIC_HEADERS}
DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}
)

install(
EXPORT ${PROJECT_NAME}Targets
FILE ${PROJECT_NAME}Targets.cmake
DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
)

configure_package_config_file(
${PROJECT_SOURCE_DIR}/cmake/${PROJECT_NAME}Config.cmake.in
${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
PATH_VARS
CMAKE_INSTALL_INCLUDEDIR
CMAKE_INSTALL_LIBDIR
)

write_basic_package_version_file(
${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
VERSION ${${PROJECT_NAME}_VERSION}
COMPATIBILITY AnyNewerVersion
)

install(
FILES
${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
)

#------------------------------------------------------------------------------

#Tests

#------------------------------------------------------------------------------
if(WITH_UT)
    enable_testing()
    find_package(GTest REQUIRED CONFIG)
    include(GoogleTest)
    add_subdirectory(ut)
endif()
