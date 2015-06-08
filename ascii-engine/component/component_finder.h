#ifndef COMPONENT_FINDER_H
#define COMPONENT_FINDER_H

#include <memory>
#include <vector>
#include "component.h"

namespace ascii_engine {

  typedef std::vector<std::unique_ptr<Component>> components_t;


  template <typename Component_type>
  struct Component_finder {

    static Component_type* find(components_t& components);

  private:

    static Component_type* result;

    static Component_type* find_and_store_in_result(components_t& components);
    static void maybe_use_as_result(Component* candidate);
    static bool dynamic_cast_is_successful(Component* candidate);
  };


  template <typename Component_type>
  Component_type* Component_finder<Component_type>::find(components_t& components) {
    result = nullptr;
    find_and_store_in_result(components);
    return result;
  }

  template <typename Component_type>
  Component_type* Component_finder<Component_type>::find_and_store_in_result(components_t& components) {
    for (auto& component : components)
      maybe_use_as_result(component.get());
  }

  template <typename Component_type>
  void Component_finder<Component_type>::maybe_use_as_result(Component* candidate) {
    if (dynamic_cast_is_successful(candidate))
      result = candidate;
  }

  template <typename Component_type>
  bool Component_finder<Component_type>::dynamic_cast_is_successful(Component* candidate) {
    return dynamic_cast<Component_type*>(candidate) != nullptr;
  }
}


#endif // COMPONENT_FINDER_H
