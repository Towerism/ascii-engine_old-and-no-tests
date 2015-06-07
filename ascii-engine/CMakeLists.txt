set(CURSES_NEED_NCURSES TRUE)
find_package(Curses REQUIRED)

add_subdirectory(display)
add_subdirectory(input)
add_subdirectory(timing)

set(asciiengine_sources engine.cpp world.cpp context.cpp entity.cpp)
add_library(asciiengine ${asciiengine_sources})

set(asciiengine_libs display input timing ${CURSES_LIBRARIES})
target_link_libraries(asciiengine ${asciiengine_libs})

