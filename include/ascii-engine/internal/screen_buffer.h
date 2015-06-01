/**********************************
 * author: Martin Fracker, Jr.
 * license: GNU GPL
 * * * * * * * * * * * * * * * * *
 * file: screen_buffer.h
 * library: ascii-engine
 **********************************/

#ifndef SCREEN_BUFFER_H
#define SCREEN_BUFFER_H

#include <vector>
#include <iostream>
#include <string>

namespace ascii_engine {

  typedef std::vector<std::vector<char>> buffer_t;

  struct Screen_buffer {

    Screen_buffer(int width, int height, char val = ' ');
    ~Screen_buffer();

    void flush();

    void put_char(int x, int y, char val);
    void put_line(int x, int y, const std::string& s);

    int get_width() const { return width; }
    int get_height() const { return height; }
    const buffer_t& get_buffer() const { return buffer; }

  private:
    int width, height;
    buffer_t buffer;

    void setup_curses_output();
    void fill_buffer_with(char val);
    void write_buffer_to_screen();
    void empty_buffer();
    bool is_in_bounds(int x, int y);
  };
}

#endif // SCREEN_BUFFER_H
