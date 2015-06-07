set(test_sources test_main.cpp)
add_executable(asciiengine_test ${test_sources})

enable_testing()

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(asciiengine_test_libs ${GTEST_LIBRARY} pthread)
target_link_libraries(asciiengine_test ${test_suite_libs})

add_test(all_tests test_suite)



