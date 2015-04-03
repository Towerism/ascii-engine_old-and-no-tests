#ifndef WORLD_H
#define WORLD_H

#include <memory>
#include <vector>
#include "entity.h"
#include "ascii-engine/display/renderer.h"

namespace ascii_engine {
    struct World {
        World(int x, int y) : renderer(x, y) { }
        void add(std::shared_ptr<Entity> e);
        void remove(std::shared_ptr<Entity> e) { remove(e.get()); }
        void remove(Entity* e);

        virtual void update(double delta_time);
    private:
        std::vector<std::shared_ptr<Entity>> entities;
        Renderer renderer;
    };
}

#endif // WORLD_H
