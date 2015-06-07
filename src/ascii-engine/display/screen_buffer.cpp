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
using namespace std;

ae::Screen_buffer::Screen_buffer(int width, int height, char val) :
  width(width), height(height), screen_output(new Curses_screen_output) {
  fill_matrix_with(val);
}

void ae::Screen_buffer::fill_matrix_with(char val) {
  for (int i = 0; i < height; ++i)
    push_filled_row_to_matrix(val);
}

void ae::Screen_buffer::push_filled_row_to_matrix(char val) {
  vector<char> row(width, val);
  char_matrix.push_back(row);
}

void ae::Screen_buffer::put_char(int x, int y, char val) {
  if (!is_in_bounds(x, y))
    return;
  char_matrix[y][x] = val;
}

bool ae::Screen_buffer::is_in_bounds(int x, int y) {
  return !char_matrix.empty() &&
    x >= 0 && y >= 0 &&
    x < width && y < height;
}

void ae::Screen_buffer::put_line(int x, int y, const string& s) {
  for (int i = x; i - x < s.length(); ++i)
    put_char(i, y, s[i - x]);
}

void ae::Screen_buffer::flush() {
  write_matrix_to_screen();
  empty_matrix();
  screen_output->refresh();
}

void ae::Screen_buffer::write_matrix_to_screen() {
  for (int j = 0; j < height; ++j)
    for (int i = 0; i < width; ++i)
      screen_output->print_char_at(j, i, char_matrix[j][i]);
}

void ae::Screen_buffer::empty_matrix() {
  for (auto& vec : char_matrix)
    fill(vec.begin(), vec.end(), ' ');
}
