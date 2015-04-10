#include <memory>
#include <algorithm>
#include "renderer.h"
#include "renderable.h"

namespace ae = ascii_engine;
using namespace std;

void ae::Renderer::add(shared_ptr<Renderable> r) {
  renderables.push_back(r);
}

void ae::Renderer::remove(ae::Renderable* r) {
  const auto& it = find_if(renderables.begin(), renderables.end(),
      [r](shared_ptr<Renderable> elem) { return elem.get() == r; }
      );
  renderables.erase(it);
}

void ae::Renderer::render() {
  for (const auto& r : renderables) {
    canvas.draw(r->get_x(), r->get_y(), r->get_graphic());
  }
  canvas.refresh();
}
