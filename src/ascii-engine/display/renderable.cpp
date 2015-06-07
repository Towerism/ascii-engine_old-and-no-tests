#include "renderable.h"

namespace ae = ascii_engine;

ae::Renderable::Renderable(int x, int y) : Renderable(x, y, "") {

}

ae::Renderable::Renderable(int x, int y, std::string s) : x(x), y(y), graphic(s) {

}

void ae::Renderable::attach_delegator(Renderable_adder_delegator* delegator) {
  this->delegator = delegator;
}

void ae::Renderable::set_graphic(const std::string& s) {
  graphic = s;
}

const std::string& ae::Renderable::get_graphic() const {
  return graphic;
}

int ae::Renderable::get_x() const {
  return x;
}

int ae::Renderable::get_y() const {
  return y;
}
