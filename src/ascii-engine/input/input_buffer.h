#ifndef INPUT_BUFFER_H
#define INPUT_BUFFER_H

namespace ascii_engine {

  struct Input_buffer {

    virtual int get_key() = 0;
    virtual bool key_is_valid(int key) = 0;
  };
}

#endif // INPUT_BUFFER_H
