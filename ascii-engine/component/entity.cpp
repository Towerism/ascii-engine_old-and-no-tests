#include "entity.h"

namespace ae = ascii_engine;

ae::Entity::Entity() : Entity(0, 0) { }

ae::Entity::Entity(int x, int y) : Entity(x, y, "") { }

ae::Entity::Entity(int x, int y, const std::string& s) : Renderable(x, y, s) { }

void ae::Entity::translate(int delta_x, int delta_y) {
  x += delta_x;
  y += delta_y;
}
