#ifndef CURSES_SCREEN_OUTPUT_H
#define CURSES_SCREEN_OUTPUT_H

#include "screen_output.h"

namespace ascii_engine {

  struct Curses_screen_output : Screen_output {

    Curses_screen_output();
    virtual ~Curses_screen_output() override;

    virtual void refresh() override;
    virtual void print_char_at(int x, int y, char c) override;
  };
}

#endif // CURSES_SCREEN_OUTPUT_H
