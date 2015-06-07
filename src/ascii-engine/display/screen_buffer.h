#ifndef SCREEN_BUFFER_H
#define SCREEN_BUFFER_H

#include <memory>
#include <boost/numeric/ublas/matrix.hpp>
#include "screen_output.h"

namespace ascii_engine {

  struct Screen_buffer {

    Screen_buffer(int width, int height);

    void flush();

    void put_char(int x, int y, char val);
    void put_line(int x, int y, const std::string& s);

  private:

    int width, height;
    std::unique_ptr<Screen_output> screen_output;

    bool is_in_bounds(int x, int y);
  };
}

#endif // SCREEN_BUFFER_H
