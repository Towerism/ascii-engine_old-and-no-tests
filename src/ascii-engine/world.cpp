#include <memory>
#include <algorithm>
#include "world.h"
#include "entity.h"

namespace ae = ascii_engine;

void ae::World::update(double delta_time) {
  update_renderables(delta_time);
}

void ae::World::update_renderables(double delta_time) {
  for (auto r : renderables)
    r->update(delta_time);
}
