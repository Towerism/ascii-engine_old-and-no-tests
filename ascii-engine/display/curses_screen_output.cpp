#include <ascii-engine/util/curses_io.h>
#include "curses_screen_output.h"

namespace ae = ascii_engine;

ae::Curses_screen_output::Curses_screen_output() {
  curses::setup_output();
}

ae::Curses_screen_output::~Curses_screen_output() {
  curses::cleanup();
}

void ae::Curses_screen_output::print_char_at(int x, int y, char c) {
  curses::print_char_at(y, x, c);
}

void ae::Curses_screen_output::refresh() {
  curses::refresh_screen();
}

void ae::Curses_screen_output::clear() {
  curses::clear_screen();
}
