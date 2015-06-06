#include "curses_input_source.h"
#include <ascii-engine/util/curses_io.h>

namespace ae = ascii_engine;

ae::Curses_input_source::Curses_input_source() {
  curses::setup_input();
}

int ae::Curses_input_source::get_key() {
  return curses::get_key();
}

bool ae::Curses_input_source::key_is_valid(int key) {
  return curses::key_is_valid(key);
}
