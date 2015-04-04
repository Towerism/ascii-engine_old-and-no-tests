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
    entities.erase(it);
    renderer.remove(e);
}

void ae::World::update(double delta_time) {
    auto it = entities.begin();
    while (it != entities.end()) {
        auto& e = it->get();
        if (e->is_pending_removal()) {
            it = remove(e); // remove and continue where iterating we left off
        } else {
            e->update();
            ++it;
        }
    }
    renderer.render();
}
