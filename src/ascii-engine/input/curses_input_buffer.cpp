#include "curses_input_buffer.h"
#include <ascii-engine/util/curses_io.h>

namespace ae = ascii_engine;

ae::Curses_input_buffer::Curses_input_buffer() {
  curses::setup_input();
}

int ae::Curses_input_buffer::get_key() {
  return curses::get_key();
}

bool ae::Curses_input_buffer::key_is_valid(int key) {
  return curses::key_is_valid(key);
}
