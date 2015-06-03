/**********************************
 * author: Martin Fracker, Jr.
 * license: GNU GPL
 * * * * * * * * * * * * * * * * *
 * file: renderer.cpp
 * library: ascii-engine
 **********************************/

#include <memory>
#include <algorithm>
#include "renderer.h"
#include "renderable.h"

namespace ae = ascii_engine;
using namespace std;

void ae::Renderer::render() {
  for (const auto& r : renderables) {
    canvas.draw(r->get_x(), r->get_y(), r->get_graphic());
  }
  canvas.refresh();
}
