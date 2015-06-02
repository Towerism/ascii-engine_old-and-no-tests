#ifndef CURSES_IO_H
#define CURSES_IO_H

#include <curses.h>
#include <string>

namespace curses {

  inline void setup_output() {
    initscr();
    curs_set(0);
    clear();
  }

  inline void setup_input() {
    noecho();
    cbreak();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
  }

  inline void refresh_screen() {
    refresh();
  }

  inline void print_char_at(int x, int y, char c) {
    mvprintw(x, y, "%c", c);
  }

  inline int get_key() {
    int key = getch();
    return key;
  }

  inline int key_is_valid(int key) {
    return key != ERR;
  }

}

#endif // CURSES_IO_H
