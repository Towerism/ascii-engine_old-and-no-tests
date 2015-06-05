#include <memory>
#include <algorithm>
#include "renderer.h"
#include "renderable.h"

namespace ae = ascii_engine;
using namespace std;

void ae::Renderer::render() {
  draw_renderables();
  canvas.refresh();
}

void ae::Renderer::draw_renderables() {
  for (const auto& r : renderables)
    canvas.draw(r->get_x(), r->get_y(), r->get_graphic());
}
