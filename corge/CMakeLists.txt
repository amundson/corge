configure_file (
  "${CMAKE_CURRENT_SOURCE_DIR}/corge_version_h.in"
  "${CMAKE_CURRENT_BINARY_DIR}/corge_version.h"
)

add_library(corge SHARED corge.cc corge.h)
target_include_directories(corge BEFORE
  PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
  PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>)
target_link_libraries(corge quux::quux)

add_executable(corgegator corgegator.cc)
target_link_libraries(corgegator corge)

install(TARGETS corge corgegator
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(FILES
        corge.h
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/corge)

