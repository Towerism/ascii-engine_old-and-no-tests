#ifndef RENDERABLE_MANAGER_H
#define RENDERABLE_MANAGER_H

#include <vector>
#include <memory>
#include "renderable_adder.h"

namespace ascii_engine {

  struct Renderable_list;
  struct Renderable;
  typedef std::vector<std::shared_ptr<Renderable>> renderables_t;

  struct Renderable_manager : Renderable_adder {

    void attach(Renderable_adder* renderable_adder);

    virtual void add(Renderable* r) override;
    virtual void add(std::shared_ptr<Renderable> r) override;

    virtual void remove(Renderable* r) override;
    virtual void remove(std::shared_ptr<Renderable> r) override;

  private:

    std::vector<Renderable_adder*> adders;

    void add_to_lists(std::shared_ptr<Renderable> r);
  };
}

#endif // RENDERABLE_MANAGER_H
