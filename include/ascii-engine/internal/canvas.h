/**********************************
 * author: Martin Fracker, Jr.
 * license: GNU GPL
 * * * * * * * * * * * * * * * * *
 * file: canvas.h
 * library: ascii-engine
 **********************************/

#ifndef CANVAS_H
#define CANVAS_H

#include <sstream>
#include "screen_buffer.h"

namespace ascii_engine {

  struct Canvas {

    Canvas(int width, int height, char val = ' ') :
      buffer(width, height, val) { }

    void draw(int x, int y, char c) { buffer.put_char(x, y, c); }
    void draw(int x, int y, const std::string& s);

    void refresh() { buffer.flush(); }

    const Screen_buffer get_buffer() const { return buffer; }

  private:

    Screen_buffer buffer;
    std::istringstream stream;

    void draw_lines_from_stream(int x, int y);
    bool there_are_more_lines();
    std::string next_line();
  };
}

#endif // CANVAS_H
