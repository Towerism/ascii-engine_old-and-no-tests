#ifndef SCREEN_BUFFER_H
#define SCREEN_BUFFER_H

#include <memory>
#include <boost/numeric/ublas/matrix.hpp>
#include "screen_output.h"

namespace ascii_engine {

  typedef std::vector<std::vector<char>> matrix_t;

  struct Screen_buffer {

    Screen_buffer(int width, int height, char val = ' ');

    void flush();

    void put_char(int x, int y, char val);
    void put_line(int x, int y, const std::string& s);

  private:

    int width, height;
    std::unique_ptr<Screen_output> screen_output;

    boost::numeric::ublas::matrix<char> char_matrix;

    bool is_in_bounds(int x, int y);
    void write_matrix_to_screen();
    void empty_matrix();
  };
}

#endif // SCREEN_BUFFER_H
