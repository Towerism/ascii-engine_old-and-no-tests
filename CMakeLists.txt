include_directories("include/ascii-engine/")

if (WIN32)
    # set these curses variables to the correct paths on your system
    set(curses_include_dir "C:/pdcurs34/")
    set(curses_lib "C:/pdcurs34/win32/pdcurses.a")
    set(CURSES_LIBRARIES pdcurses) # the name of the lib, ncurses on unix
    add_library(${curses_lib} STATIC IMPORTED)
elseif (UNIX)
    set(CURSES_NEED_NCURSES TRUE)
    find_package(Curses REQUIRED)
    set(curses_include_dir ${CURSES_INCLUDE_DIR})
    set(curses_lib ${CURSES_LIBRARIES})
endif (WIN32)
include_directories(${curses_include_dir})

add_subdirectory(display)
add_subdirectory(input)


set(asciiengine_sources engine.cpp world.cpp)
add_library(asciiengine ${asciiengine_sources})

set(asciiengine_libs display input ${curses_lib})
target_link_libraries(asciiengine ${asciiengine_libs})

