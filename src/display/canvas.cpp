/**********************************
 * author: Martin Fracker, Jr.
 * license: GNU GPL
 * * * * * * * * * * * * * * * * *
 * file: canvas.cpp
 * library: ascii-engine
 **********************************/

#include <sstream>
#include <string>
#include "canvas.h"

namespace ae = ascii_engine;
using namespace std;

void ae::Canvas::draw(int x, int y, const string& s) {
  prepare_stream(s);
  stream_contents_to_buffer(x, y);
  make_stream_good();
}

void ae::Canvas::prepare_stream(const std::string& s) {
  stream.str(s);
}

void ae::Canvas::stream_contents_to_buffer(int x, int y) {
  for (int i = y; there_are_more_lines(); ++i)
    add_next_line_to_buffer(x, i);
}

void ae::Canvas::add_next_line_to_buffer(int x, int y) {
  string line = next_line();
  buffer.put_line(x, y, line);
}

void ae::Canvas::make_stream_good() {
  stream.clear();
}

bool ae::Canvas::there_are_more_lines() {
  return stream.good();
}

string ae::Canvas::next_line() {
  string line;
  getline(stream, line);
  return line;
}
