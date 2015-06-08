template <typename Component_type> // emacs modeset -*- mode: c++;-*-
Component_type* Component_finder<Component_type>::find(std::vector<std::unique_ptr<Component>>& components) {
  for (auto& component : components)
    maybe_use_as_result(component.get());
  return result;
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

