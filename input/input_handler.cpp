/**********************************
 * author: Martin Fracker, Jr.
 * license: GNU GPL
 * * * * * * * * * * * * * * * * *
 * file: input_handler.cpp
 * library: ascii-engine
 **********************************/

#include <algorithm>
#include <curses.h>
#include "input_handler.h"

namespace ae = ascii_engine;

ae::Input_handler::Input_handler() {
  setup_curses_input();
}

void ae::Input_handler::setup_curses_input() {
  raw();
  noecho();
  cbreak();
  nodelay(stdscr, TRUE);
  keypad(stdscr, TRUE);
}

void ae::Input_handler::poll() {
  input_vec.clear();
  collect_keys_pressed();
}

void ae::Input_handler::collect_keys_pressed() {
  while(true) {
    int c = getch();
    if (c == ERR) {
      break;
    }
    input_vec.push_back(c);
  }
}

bool ae::Input_handler::check_key(int key) {
  const auto it = find(input_vec.begin(), input_vec.end(), key);
  return was_pressed(it);
}

bool ae::Input_handler::was_pressed(std::vector<int>::const_iterator it) {
  bool pressed = it != input_vec.end();
  if (pressed) {
    input_vec.erase(it);
  }
  return pressed;
}
