#ifndef CONTEXT_H
#define CONTEXT_H

#include <ascii-engine/display/renderer.h>
#include <ascii-engine/display/renderable_adder_delegator.h>
#include "world.h"

namespace ascii_engine {

  struct Context : Renderable_adder_delegator {

    Context(int width, int height);

    void update(double delta_time);

  private:

    World world;
    Renderer renderer;
  };
}

#endif // CONTEXT_H
