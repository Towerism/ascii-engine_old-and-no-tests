#include <algorithm>
#include <ascii-engine/util/curses_io.h>
#include "input_buffer.h"

namespace ae = ascii_engine;

void ae::Input_buffer::poll() {
  buffer.clear();
  collect_keys_pressed();
}

void ae::Input_buffer::collect_keys_pressed() {
  do collect_next_key();
  while(input_source->key_is_valid(last_key_pressed));
}

void ae::Input_buffer::collect_next_key() {
  last_key_pressed = input_source->get_key();
  maybe_push_key_back(last_key_pressed);
}

void ae::Input_buffer::maybe_push_key_back(int key) {
  if (input_source->key_is_valid(key))
    buffer.push_back(key);
}

bool ae::Input_buffer::check_key(int key) {
  const auto it = std::find(buffer.begin(), buffer.end(), key);
  return was_pressed(it);
}

bool ae::Input_buffer::was_pressed(std::vector<int>::const_iterator it) {
  bool pressed = it != buffer.end();
  if (pressed)
    buffer.erase(it);
  return pressed;
}
