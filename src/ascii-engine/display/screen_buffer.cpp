/**********************************
 * author: Martin Fracker, Jr.
 * license: GNU GPL
 * * * * * * * * * * * * * * * * *
 * file: screen_buffer.cpp
 * library: ascii-engine
 **********************************/

#include <algorithm>
#include "screen_buffer.h"
#include "curses_screen_output.h"

namespace ae = ascii_engine;

ae::Screen_buffer::Screen_buffer(int width, int height) :
  width(width), height(height), screen_output(new Curses_screen_output) {
}

void ae::Screen_buffer::put_char(int x, int y, char val) {
  if (!is_in_bounds(x, y))
    return;
  screen_output->print_char_at(x, y, val);
}

bool ae::Screen_buffer::is_in_bounds(int x, int y) {
  return x >= 0 && y >= 0 &&
         x < width && y < height;
}

void ae::Screen_buffer::put_line(int x, int y, const std::string& s) {
  for (int i = x; i - x < s.length(); ++i)
    put_char(i, y, s[i - x]);
}

void ae::Screen_buffer::flush() {
  screen_output->refresh();
  screen_output->clear();
}
