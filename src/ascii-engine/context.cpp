#include <memory>
#include "context.h"
#include "world.h"

namespace ae = ascii_engine;
using namespace std;

ae::Context::Context(int width, int height) : renderer(width, height) {
  attach(&world);
  attach(&renderer);
}

void ae::Context::update(double delta_time) {
  world.update(delta_time);
  renderer.render();
}
