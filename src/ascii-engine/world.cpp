/**********************************
 * author: Martin Fracker, Jr.
 * license: GNU GPL
 * * * * * * * * * * * * * * * * *
 * file: world.cpp
 * library: ascii-engine
 **********************************/

#include <memory>
#include <algorithm>
#include "world.h"
#include "entity.h"

namespace ae = ascii_engine;
using namespace std;

ae::World::World(int width, int height) : renderer(width, height) {
  renderable_remover.attach_renderable_list(this);
  renderable_remover.attach_renderable_list(&renderer);
}

void ae::World::add(std::shared_ptr<Renderable> r) {
  Renderable_list::add(r);
  r->attach_remover(renderable_remover);
  renderer.add(r);
}

void ae::World::update(double delta_time) {
  update_renderables(delta_time);
  renderer.render();
}

void ae::World::update_renderables(double delta_time) {
  for (auto r : renderables)
    r->update(delta_time);
}
