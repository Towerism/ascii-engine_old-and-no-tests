set(input_sources input_buffer.cpp curses_input_source.cpp)
add_library(input ${input_sources})

include_directories(input PUBLIC ${curses_include_dir})
target_link_libraries(input ${curses_lib})
