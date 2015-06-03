/**********************************
 * author: Martin Fracker, Jr.
 * license: GNU GPL
 * * * * * * * * * * * * * * * * *
 * file: screen_buffer.cpp
 * library: ascii-engine
 **********************************/

#include <iostream>
#include <algorithm>
#include <ascii-engine/util/curses_io.h>
#include "screen_buffer.h"

namespace ae = ascii_engine;
using namespace std;

ae::Screen_buffer::Screen_buffer(int width, int height, char val) :
  width(width), height(height) {
  curses::setup_output();
  fill_buffer_with(val);
}

void ae::Screen_buffer::fill_buffer_with(char val) {
  for (int i = 0; i < height; ++i)
    push_filled_row_to_buffer(val);
}

void ae::Screen_buffer::push_filled_row_to_buffer(char val) {
  vector<char> row(width, val);
  buffer.push_back(row);
}

ae::Screen_buffer::~Screen_buffer() {
  endwin();
  clear();
}

void ae::Screen_buffer::put_char(int x, int y, char val) {
  if (!is_in_bounds(x, y))
    return;
  buffer[y][x] = val;
}

bool ae::Screen_buffer::is_in_bounds(int x, int y) {
  return !buffer.empty() &&
    x >= 0 && y >= 0 &&
    x < width && y < height;
}

void ae::Screen_buffer::put_line(int x, int y, const string& s) {
  for (int i = x; i - x < s.length(); ++i)
    put_char(i, y, s[i - x]);
}

void ae::Screen_buffer::flush() {
  write_buffer_to_screen();
  empty_buffer();
  curses::refresh_screen();
}

void ae::Screen_buffer::write_buffer_to_screen() {
  for (int i = 0; i < width; ++i)
    for (int j = 0; j < height; ++j)
      curses::print_char_at(j, i, buffer[j][i]);
}

void ae::Screen_buffer::empty_buffer() {
  for (auto& vec : buffer)
    fill(vec.begin(), vec.end(), ' ');
}
