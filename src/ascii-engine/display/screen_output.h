#ifndef SCREEN_OUTPUT_H
#define SCREEN_OUTPUT_H

namespace ascii_engine {

  struct Screen_output {

    virtual ~Screen_output() { }

    virtual void refresh() = 0;
    virtual void print_char_at(int x, int y, char c) = 0;
  };
}

#endif // SCREEN_OUTPUT_H
