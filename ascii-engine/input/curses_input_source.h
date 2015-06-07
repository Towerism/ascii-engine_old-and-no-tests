#ifndef CURSES_INPUT_SOURCE
#define CURSES_INPUT_SOURCE

#include "input_source.h"

namespace ascii_engine {

  struct Curses_input_source : Input_source {

    Curses_input_source();
    virtual ~Curses_input_source() override;

    virtual int get_key() override;
    virtual bool key_is_valid(int key) override;
  };
}

#endif // CURSES_INPUT_SOURCE
