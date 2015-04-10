#ifndef WORLD_H
#define WORLD_H

#include <memory>
#include <vector>
#include "entity.h"
#include "ascii-engine/display/renderer.h"

namespace ascii_engine {
  typedef std::vector<std::shared_ptr<Entity>> entities_t;
  struct World {
    World(int width, int height) : renderer(width, height) { }
    ~World();
    void add(std::shared_ptr<Entity> e);
    void remove(std::shared_ptr<Entity> e) { remove(e.get()); }
    void remove(Entity* e);

    virtual void update(double delta_time);
    private:
    entities_t entities;

    // we don't want to expose any iterators
    // that's why this is private
    entities_t::iterator remove_it(entities_t::iterator it);

    Renderer renderer;
  };
}

#endif // WORLD_H
