#ifndef RENDERABLE_LIST_H
#define RENDERABLE_LIST_H

#include <algorithm>
#include <memory>
#include <vector>

namespace ascii_engine {

  struct Renderable;
  typedef std::vector<std::shared_ptr<Renderable>> renderables_t;

  struct Renderable_list {

    virtual void add(std::shared_ptr<Renderable> r);
    void remove(std::shared_ptr<Renderable> r);
    void remove(Renderable* r);

  protected:

    renderables_t renderables;

    renderables_t::iterator find_renderable_from_ptr(Renderable* r);

  };
}

#endif // RENDERABLE_LIST_H
