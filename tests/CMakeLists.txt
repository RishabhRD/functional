file(GLOB_RECURSE test_list "*test.cpp")
add_executable(functional_tests ${test_list})
target_include_directories(functional_tests PRIVATE ../include)
target_link_libraries(functional_tests PRIVATE project_warnings)
target_link_libraries(functional_tests PUBLIC doctest::doctest)
target_link_libraries(functional_tests PRIVATE project_options)
add_test(NAME functional_tests COMMAND functional_tests)
