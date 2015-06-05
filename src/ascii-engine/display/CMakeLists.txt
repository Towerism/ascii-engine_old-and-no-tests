set(display_sources canvas.cpp renderer.cpp screen_buffer.cpp
                    renderable_list.cpp renderable_manager.cpp)
add_library(display ${display_sources})
include_directories(display PUBLIC ${curses_include_dir})
target_link_libraries(display ${curses_lib})
