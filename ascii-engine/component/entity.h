#ifndef ENTITY_H
#define ENTITY_H

#include <memory>
#include <vector>
#include <ascii-engine/display/renderable.h>
#include "component_finder.h"

namespace ascii_engine {

  struct Component;

  struct Entity {

    Entity();
    Entity(int x, int y);
    Entity(int x, int y, const std::string& s);

    void add_component(Component* component);

    void translate(int delta_x, int delta_y);

    template <typename Component_type>
    Component_type* get_component();

    int get_x() const { return x; }
    int get_y() const { return y; }

  private:

    int x, y;

    std::vector<std::unique_ptr<Component>> components;

  };

  template <typename Component_type>
  Component_type* Entity::get_component() {
    return Component_finder<Component_type>::find(components);
  }
}

#endif // ENTITY_H
