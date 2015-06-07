#include <sstream>
#include <string>
#include "canvas.h"

namespace ae = ascii_engine;

using std::string;

void ae::Canvas::draw(int x, int y, const std::string& s) {
  prepare_stream(s);
  stream_contents_to_buffer_at_pos(x, y);
  make_stream_good();
}

void ae::Canvas::prepare_stream(const std::string& s) {
  stream.str(s);
}

void ae::Canvas::stream_contents_to_buffer_at_pos(int x, int y) {
  for (int i = y; there_are_more_lines(); ++i)
    add_next_line_to_buffer_at_pos(x, i);
}

bool ae::Canvas::there_are_more_lines() {
  return stream.good();
}

void ae::Canvas::add_next_line_to_buffer_at_pos(int x, int y) {
  string line = next_line();
  buffer.put_line(x, y, line);
}

string ae::Canvas::next_line() {
  string line;
  getline(stream, line);
  return line;
}

void ae::Canvas::make_stream_good() {
  stream.clear();
}
