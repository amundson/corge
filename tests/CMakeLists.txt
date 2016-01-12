add_executable(test_corge test_corge.cc)
target_link_libraries(test_corge corge)
add_test(NAME test_corge COMMAND $<TARGET_FILE:test_corge>)
