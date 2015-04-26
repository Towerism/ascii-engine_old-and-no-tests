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

#undef box
#undef clear
#undef erase
#undef move
#undef refresh

namespace ae = ascii_engine;

ae::Input_handler::Input_handler() {
  raw();
  noecho();
  cbreak();
  nodelay(stdscr, TRUE);
  keypad(stdscr, TRUE);
}

void ae::Input_handler::poll() {
  int c;
  // clear keys unused from last poll
  input_vec.clear();
  while(true) {
    c = getch();
    if (c == ERR) {
      break;
    }
    input_vec.push_back(c);
  }
}

bool ae::Input_handler::check_key(int key) {
  const auto& it = find_if(input_vec.begin(), input_vec.end(),
      [key](int elem) { return elem == key; }
      );
  if (it != input_vec.end()) {
    input_vec.erase(it);
    return true;
  }
  return false;
}
