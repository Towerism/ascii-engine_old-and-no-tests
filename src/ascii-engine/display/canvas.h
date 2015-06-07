#ifndef CANVAS_H
#define CANVAS_H

#include <sstream>
#include "screen_buffer.h"

namespace ascii_engine {

  struct Canvas {

    Canvas(int width, int height) :
      buffer(width, height) { }

    void draw(int x, int y, char c) { buffer.put_char(x, y, c); }
    void draw(int x, int y, const std::string& s);

    void refresh() { buffer.flush(); }

  private:

    Screen_buffer buffer;
    std::istringstream stream;

    void prepare_stream(const std::string&);
    void stream_contents_to_buffer(int x, int y);
    void make_stream_good();
    bool there_are_more_lines();
    void add_next_line_to_buffer(int x, int y);
    std::string next_line();
  };
}

#endif // CANVAS_H
