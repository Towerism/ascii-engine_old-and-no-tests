set(display_sources canvas.cpp renderer.cpp screen_buffer.cpp)
add_library(display ${display_sources})
target_include_directories(display PUBLIC ${curses_include_dir})
target_link_libraries(display ${curses_lib_name})
