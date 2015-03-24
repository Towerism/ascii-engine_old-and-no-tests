include_directories("${CMAKE_SOURCE_DIR}/include/ascii-engine/")
include_directories(".")

add_subdirectory(display)
add_subdirectory(input)

set(asciiengine_sources engine.cpp world.cpp)
add_library(asciiengine ${asciiengine_sources})

set(asciiengine_libs display input)
target_link_libraries(asciiengine ${asciiengine_libs})

