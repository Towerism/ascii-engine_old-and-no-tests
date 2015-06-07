#ifndef RENDERABLE_LIST_H
#define RENDERABLE_LIST_H

#include <memory>
#include <vector>
#include "renderable_adder.h"

namespace ascii_engine {

  struct Renderable;
  typedef std::vector<std::shared_ptr<Renderable>> renderables_t;

  struct Renderable_list : Renderable_adder {

    virtual void add(Renderable* r) override;
    virtual void add(std::shared_ptr<Renderable> r) override;

    virtual void remove(Renderable* r) override;
    virtual void remove(std::shared_ptr<Renderable> r) override;

  protected:

    renderables_t renderables;

    renderables_t::iterator find_renderable_from_ptr(Renderable* r);

  };
}

#endif // RENDERABLE_LIST_H
