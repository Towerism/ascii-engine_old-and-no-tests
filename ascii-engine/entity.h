#ifndef ENTITY_H
#define ENTITY_H

#include <ascii-engine/display/renderable.h>

namespace ascii_engine {

  struct Entity : Renderable {

    Entity();
    Entity(int x, int y);
    Entity(int x, int y, const std::string& s);

    void translate(int delta_x, int delta_y);
  };
}

#endif // ENTITY_H
