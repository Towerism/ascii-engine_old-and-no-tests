#include "context.h"

namespace ae = ascii_engine;

ae::Context::Context(int width, int height) : renderer(width, height) {
  attach_delegate(&world);
  attach_delegate(&renderer);
}

void ae::Context::update(double delta_time) {
  world.update(delta_time);
  renderer.render();
}
