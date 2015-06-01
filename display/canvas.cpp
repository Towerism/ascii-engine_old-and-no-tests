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
  stream.str(s);
  draw_lines_from_stream(x, y);
}

void ae::Canvas::draw_lines_from_stream(int x, int y) {
  for (int i = y; there_are_more_lines(); ++i) {
    string line = next_line();
    buffer.put_line(x, i, line);
  }
}

bool ae::Canvas::there_are_more_lines() {
  return stream.good();
}

string ae::Canvas::next_line() {
  string line;
  getline(stream, line);
  return line;
}
