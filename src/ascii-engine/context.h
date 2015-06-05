#ifndef CONTEXT_H
#define CONTEXT_H

#include <memory>
#include <ascii-engine/display/renderer.h>
#include <ascii-engine/display/renderable_manager.h>
#include <ascii-engine/display/renderable_adder.h>
#include "world.h"

namespace ascii_engine {

  struct Context : Renderable_manager {

    Context(int width, int height);

    void update(double delta_time);

  private:

    World world;
    Renderer renderer;
  };
}

#endif // CONTEXT_H
