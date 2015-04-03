include_directories("include/ascii-engine/")

add_subdirectory(display)
add_subdirectory(input)

set(asciiengine_sources engine.cpp world.cpp)
add_library(asciiengine ${asciiengine_sources})

set(asciiengine_libs display input)
target_link_libraries(asciiengine ${asciiengine_libs})

