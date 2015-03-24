set(input_sources input_handler.cpp)
add_library(input ${input_sources})
target_include_directories(input PUBLIC ${curses_include_dir})
target_link_libraries(input ${curses_lib_name})