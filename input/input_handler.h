/**********************************
 * author: Martin Fracker, Jr.
 * license: GNU GPL
 * * * * * * * * * * * * * * * * *
 * file: input_handler.h
 * library: ascii-engine
 **********************************/

#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <vector>

namespace ascii_engine {

  struct Input_handler {

    static Input_handler& get_instance() {
      static Input_handler instance;
      return instance;
    }

    Input_handler();
    void setup_curses_input();

    void poll();
    bool check_key(int key_code);

  private:

    std::vector<int> input_vec;

    void collect_keys_pressed();
    bool was_pressed(int key);

    Input_handler(const Input_handler&) = delete;
    void operator=(const Input_handler&) = delete;
  };
}

#endif // INPUT_HANDLER_H
