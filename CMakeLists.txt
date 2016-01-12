cmake_minimum_required(VERSION 3.0.0)
project(CORGE)
set(CORGE_VERSION_MAJOR 1)
set(CORGE_VERSION_MINOR 0)
set(CORGE_VERSION "${CORGE_VERSION_MAJOR}.${CORGE_VERSION_MINOR}")

find_package(Quux 1.0 EXACT REQUIRED CONFIG)
include_directories(${QUUX_INCLUDE_DIR})
link_directories(${QUUX_LIB_DIR})

set(INCLUDE_INSTALL_DIR include/ CACHE PATH "install directory")
set(LIB_INSTALL_DIR lib/ CACHE PATH "lib directory")

include_directories(BEFORE ${CORGE_SOURCE_DIR})
enable_testing()

include(CMakePackageConfigHelpers)

configure_package_config_file(CorgeConfig.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/CorgeConfig.cmake
  INSTALL_DESTINATION ${LIB_INSTALL_DIR}/corge/cmake
  PATH_VARS INCLUDE_INSTALL_DIR LIB_INSTALL_DIR)

write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/CorgeConfigVersion.cmake
  VERSION ${CORGE_VERSION}
  COMPATIBILITY ExactVersion)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/CorgeConfig.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/CorgeConfigVersion.cmake
        DESTINATION ${LIB_INSTALL_DIR}/corge/cmake)

add_subdirectory(corge)
add_subdirectory(tests)
