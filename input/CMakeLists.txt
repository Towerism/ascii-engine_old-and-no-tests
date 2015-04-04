set(input_sources input_handler.cpp)
add_library(input ${input_sources})
target_link_libraries(input ${CURSES_LIBRARIES})
