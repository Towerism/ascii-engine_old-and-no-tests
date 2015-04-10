#include <algorithm>
#include <curses.h>
#include "input_handler.h"

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
  input_map.clear();
  while(true) {
    c = getch();
    if (c == ERR) {
      break;
    }
    input_map.insert(std::make_pair(c, c));
  }
}

bool ae::Input_handler::check_key(int key) {
  const auto& it = find_if(input_map.begin(), input_map.end(),
      [key](const std::pair<int, int>& elem) { return elem.first == key; }
      );
  if (it != input_map.end()) {
    input_map.erase(it);
    return true;
  }
  return false;
}
