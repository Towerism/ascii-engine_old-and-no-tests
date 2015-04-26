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
  istringstream iss(s);
  int j = y;
  while (iss.good() && !s.empty() && j < buffer.get_height()) {
    string line;
    getline(iss, line);
    for (unsigned i = x; i < (unsigned)buffer.get_width() && i - x < line.length(); ++i) {
      if (i < 0 || j < 0) {
        continue;
      }
      buffer.set_char(i, j, line[i - x]);
    }
    ++j;
  }
}
