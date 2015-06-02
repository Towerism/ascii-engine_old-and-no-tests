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

void ae::Input_handler::poll() {
  ensure_curses_input();
  input_vec.clear();
  collect_keys_pressed();
}

void ae::Input_handler::ensure_curses_input() {
  noecho();
  cbreak();
  nodelay(stdscr, TRUE);
  keypad(stdscr, TRUE);
}

void ae::Input_handler::collect_keys_pressed() {
  do {
    last_key_pressed = next_key();
    maybe_push_key_back(last_key_pressed);
  } while(key_is_valid(last_key_pressed));
}

int ae::Input_handler::next_key() {
  int key = getch();
  return key;
}

void ae::Input_handler::maybe_push_key_back(int key) {
  if (key_is_valid(key))
    input_vec.push_back(key);
}

bool ae::Input_handler::key_is_valid(int key) {
  return key != ERR;
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
