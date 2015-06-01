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

ae::World::~World() {
  for (auto& e : entities) {
    remove(e);
  }
}

void ae::World::add(shared_ptr<ae::Entity> e) {
  entities.push_back(e);
  renderer.add(e);
}

void ae::World::remove(ae::Entity* e) {
  const auto& it = find_if(entities.begin(), entities.end(),
      [e](shared_ptr<Entity> elem) { return elem.get() == e; }
      );
  remove_it(it);
}

ae::entities_t::iterator ae::World::remove_it(ae::entities_t::iterator it) {
  renderer.remove(it->get());
  return entities.erase(it);
}

void ae::World::update(double delta_time) {
  auto it = entities.begin();
  while (it != entities.end()) {
    const auto& e = it->get();
    if (e->is_pending_removal()) {
      // remove and continue where iterating we left off
      it = remove_it(it);
    } else {
      e->update(delta_time);
      ++it;
    }
  }
  renderer.render();
}
