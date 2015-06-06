#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <memory>
#include <vector>
#include "curses_input_buffer.h"

namespace ascii_engine {

  struct Input_handler {

    static Input_handler& get() {
      static Input_handler instance;
      return instance;
    }

    void poll();
    bool check_key(int key_code);

  private:

    Input_handler() : input_buffer(new Curses_input_buffer) { }

    std::unique_ptr<Input_buffer> input_buffer;
    std::vector<int> input_vec;
    int last_key_pressed;

    void collect_keys_pressed();
    void collect_next_key();
    void maybe_push_key_back(int key);
    bool was_pressed(std::vector<int>::const_iterator it);

    Input_handler(const Input_handler&) = delete;
    void operator=(const Input_handler&) = delete;
  };
}

#endif // INPUT_HANDLER_H
