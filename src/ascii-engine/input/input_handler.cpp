#include <algorithm>
#include <ascii-engine/util/curses_io.h>
#include "input_handler.h"

using namespace std;
namespace ae = ascii_engine;

void ae::Input_handler::poll() {
  curses::setup_input();
  input_vec.clear();
  collect_keys_pressed();
}

void ae::Input_handler::collect_keys_pressed() {
  do collect_next_key();
  while(curses::key_is_valid(last_key_pressed));
}

void ae::Input_handler::collect_next_key() {
  last_key_pressed = curses::get_key();
  maybe_push_key_back(last_key_pressed);
}

void ae::Input_handler::maybe_push_key_back(int key) {
  if (curses::key_is_valid(key))
    input_vec.push_back(key);
}

bool ae::Input_handler::check_key(int key) {
  const auto it = find(input_vec.begin(), input_vec.end(), key);
  return was_pressed(it);
}

bool ae::Input_handler::was_pressed(vector<int>::const_iterator it) {
  bool pressed = it != input_vec.end();
  if (pressed)
    input_vec.erase(it);
  return pressed;
}
