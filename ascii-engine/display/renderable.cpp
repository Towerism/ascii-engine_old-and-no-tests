#include "renderable.h"

namespace ae = ascii_engine;

ae::Renderable::Renderable() : Renderable("") {

}

ae::Renderable::Renderable(std::string s) : graphic(s) {

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
