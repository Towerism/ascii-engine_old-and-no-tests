cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
include_directories("include/ascii-engine/")
include_directories(".")

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

if (${CMAKE_CURRENT_LIST_DIR} STREQUAL ${CMAKE_SOURCE_DIR})
    list( APPEND CMAKE_CXX_FLAGS "-std=c++14 ${CMAKE_CXX_FLAGS} -ggdb -O0 -ftest-coverage -fprofile-arcs")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/test/bin)
    include_directories(../)
    add_subdirectory(test)
endif(${CMAKE_CURRENT_LIST_DIR} STREQUAL ${CMAKE_SOURCE_DIR})

add_subdirectory(display)
add_subdirectory(input)
add_subdirectory(timing)

set(asciiengine_sources engine.cpp world.cpp)
add_library(asciiengine ${asciiengine_sources})

set(asciiengine_libs display input timing ${curses_lib})
target_link_libraries(asciiengine ${asciiengine_libs})

