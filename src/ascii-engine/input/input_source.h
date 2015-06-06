#ifndef INPUT_SOURCE_H
#define INPUT_SOURCE_H

namespace ascii_engine {

  struct Input_source {

    virtual int get_key() = 0;
    virtual bool key_is_valid(int key) = 0;
  };
}

#endif // INPUT_SOURCE_H
