cmake_minimum_required(VERSION 3.0.0)
project(CORGE VERSION 2.0.0)

find_package(Quux 2.0.0 REQUIRED CONFIG)

include(GNUInstallDirs)

enable_testing()

add_subdirectory(corge)
add_subdirectory(tests)

include(CMakePackageConfigHelpers)

# - Versioning File (Same for Build/Install Trees)
write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/CorgeConfigVersion.cmake
  VERSION ${CORGE_VERSION}
  COMPATIBILITY ExactVersion)

# - Build Tree Config/Targets Files
set(CORGE_EXPORTED_INCLUDEDIR "${PROJECT_SOURCE_DIR}")
set(CORGE_EXPORTED_LIBDIR "${PROJECT_BINARY_DIR}/corge")

configure_package_config_file(CorgeConfig.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/CorgeConfig.cmake
  INSTALL_DESTINATION ${CMAKE_CURRENT_BINARY_DIR}
  INSTALL_PREFIX ${CMAKE_CURRENT_BINARY_DIR}
  PATH_VARS CORGE_EXPORTED_INCLUDEDIR CORGE_EXPORTED_LIBDIR)

# NB: must be called after EXPORT argument is defined,
# hence moving add_subdirectory earlier.
export(EXPORT CorgeTargets NAMESPACE corge::)

# - Install Tree Config/Targets Files
set(CORGE_EXPORTED_INCLUDEDIR "${CMAKE_INSTALL_INCLUDEDIR}")
set(CORGE_EXPORTED_LIBDIR "${CMAKE_INSTALL_LIBDIR}")

configure_package_config_file(CorgeConfig.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/InstallTreeFiles/CorgeConfig.cmake
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/corge
  PATH_VARS CORGE_EXPORTED_INCLUDEDIR CORGE_EXPORTED_LIBDIR)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/InstallTreeFiles/CorgeConfig.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/CorgeConfigVersion.cmake
              DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/corge)
install(EXPORT CorgeTargets
        NAMESPACE corge::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/corge)


