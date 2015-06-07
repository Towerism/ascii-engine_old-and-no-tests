cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

include_directories(src)
add_subdirectory(src/ascii-engine)

option(ASCII_ENGINE_TESTS "ASCII_ENGINE_TESTS" OFF)

if (${ASCII_ENGINE_TESTS})
  list(APPEND CMAKE_CXX_FLAGS "-std=c++14 ${CMAKE_CXX_FLAGS} -ggdb -O0 -ftest-coverage -fprofile-arcs")
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/test)
  add_subdirectory(test)
endif()
