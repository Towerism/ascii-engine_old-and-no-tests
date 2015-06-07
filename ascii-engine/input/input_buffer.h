#ifndef INPUT_BUFFER_H
#define INPUT_BUFFER_H

#include <memory>
#include <vector>
#include "input_source.h"
#include "curses_input_source.h"

namespace ascii_engine {

  struct Input_buffer {

    static Input_buffer& get() {
      static Input_buffer instance;
      return instance;
    }

    void poll();
    bool check_key(int key_code);

  private:

    Input_buffer() : input_source(new Curses_input_source) { }

    std::unique_ptr<Input_source> input_source;
    std::vector<int> buffer;
    int last_key_pressed;

    void collect_keys_pressed();
    void collect_next_key();
    void maybe_push_key_back(int key);
    bool was_pressed(std::vector<int>::const_iterator it);

    Input_buffer(const Input_buffer&) = delete;
    void operator=(const Input_buffer&) = delete;
  };
}

#endif // INPUT_BUFFER_H
