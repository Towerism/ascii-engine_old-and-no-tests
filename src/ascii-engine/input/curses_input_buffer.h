#ifndef CURSES_INPUT_BUFFER
#define CURSES_INPUT_BUFFER

#include "input_buffer.h"

namespace ascii_engine {
  struct Curses_input_buffer : Input_buffer {

    virtual int get_key() override;
    virtual bool key_is_valid(int key) override;
  };
}

#endif // CURSES_INPUT_BUFFER
