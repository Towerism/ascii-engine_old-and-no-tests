#ifndef RENDERABLE_ADDER_H
#define RENDERABLE_ADDER_H

#include <memory>
#include "renderable.h"

namespace ascii_engine {

  struct Renderable;

  struct Renderable_adder {

    virtual void add(Renderable* r) = 0;
    virtual void add(std::shared_ptr<Renderable> r) = 0;

    virtual void remove(Renderable* r) = 0;
    virtual void remove(std::shared_ptr<Renderable> r) = 0;
  };
}

#endif // RENDERABLE_ADDER_H
