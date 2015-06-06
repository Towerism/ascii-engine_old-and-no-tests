#include "curses_input_buffer.h"
#include <curses.h>

namespace ae = ascii_engine;

int ae::Curses_input_buffer::get_key() {
  return getch();
}

bool ae::Curses_input_buffer::key_is_valid(int key) {
  return key != ERR;
}
