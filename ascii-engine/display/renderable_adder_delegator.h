#ifndef RENDERABLE_ADDER_DELEGATOR_H
#define RENDERABLE_ADDER_DELEGATOR_H

#include <vector>
#include <memory>
#include "renderable_adder.h"

namespace ascii_engine {

  struct Renderable;
  typedef std::vector<std::shared_ptr<Renderable>> renderables_t;

  struct Renderable_adder_delegator : Renderable_adder {

    void attach_delegate(Renderable_adder* renderable_adder);

    virtual void add(Renderable* r) override;
    virtual void add(std::shared_ptr<Renderable> r) override;

    virtual void remove(Renderable* r) override;
    virtual void remove(std::shared_ptr<Renderable> r) override;

  private:

    std::vector<Renderable_adder*> delegates;

    void add_to_lists(std::shared_ptr<Renderable> r);
  };
}

#endif // RENDERABLE_ADDER_DELEGATOR_H
