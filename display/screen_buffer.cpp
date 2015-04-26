/**********************************
 * author: Martin Fracker, Jr.
 * license: GNU GPL
 * * * * * * * * * * * * * * * * *
 * file: screen_buffer.cpp
 * library: ascii-engine
 **********************************/

#include <iostream>
#include <algorithm>
#include <curses.h>
#include "screen_buffer.h"

namespace ae = ascii_engine;
using namespace std;

ae::Screen_buffer::Screen_buffer(int width, int height, char val) :
  width(width), height(height) {
    // set up console for curses
    initscr();
    curs_set(0);
    clear();
    // initialize the container
    for (int i = 0; i < height; ++i) {
      vector<char> row(width, val);
      buffer.push_back(row);
    }
  }

ae::Screen_buffer::~Screen_buffer() { 
  endwin();
  clear();
}

void ae::Screen_buffer::purge() {
  for (auto& vec : buffer) {
    fill(vec.begin(), vec.end(), ' ');
  }
}

void ae::Screen_buffer::set_char(int x, int y, char val) {
  buffer[y][x] = val;
}

void ae::Screen_buffer::flush() {
  for (int i = 0; i < width; ++i) {
    for (int j = 0; j < height; ++j) {
      mvprintw(j, i, "%c", buffer.at(j).at(i));
    }
  }
  // empty the buffer
  purge();
  // refresh the screen
  refresh();
}
