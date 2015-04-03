#ifndef ENTITY_H
#define ENTITY_H

#include "ascii-engine/display/renderable.h"

namespace ascii_engine {
    struct Entity : Renderable {
        Entity() : Entity(0, 0) { }
        Entity(int x, int y) : Entity(x, y, "") { }
        Entity(int x, int y, const string& s) : Renderable(x, y, s) { }

        virtual void update(double delta_time) { }
    };
}

#endif // ENTITY_H
