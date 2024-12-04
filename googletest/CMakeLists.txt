project(fraction_test)
add_subdirectory(googletest)

add_executable(fraction_test_run tests.cpp)

target_link_libraries(fraction_test_run src_lib)
target_link_libraries(fraction_test_run gtest gtest_main)
