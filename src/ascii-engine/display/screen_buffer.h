#ifndef SCREEN_BUFFER_H
#define SCREEN_BUFFER_H

#include <vector>
#include <iostream>
#include <string>

namespace ascii_engine {

  typedef std::vector<std::vector<char>> matrix_t;

  struct Screen_buffer {

    Screen_buffer(int width, int height, char val = ' ');
    ~Screen_buffer();

    void flush();

    void put_char(int x, int y, char val);
    void put_line(int x, int y, const std::string& s);

  private:

    int width, height;
    matrix_t char_matrix;

    void setup_curses_output();
    void fill_buffer_with(char val);
    void push_filled_row_to_buffer(char val);
    bool is_in_bounds(int x, int y);
    void write_buffer_to_screen();
    void empty_buffer();
  };
}

#endif // SCREEN_BUFFER_H
