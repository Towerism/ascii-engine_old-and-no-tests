#include "engine.h"

namespace ae = ascii_engine;
using namespace std;

void ae::Engine::game_loop() {
  in_loop = true;
  while (!exit_loop)
    update_frame();
}

void ae::Engine::update_frame() {
  fps_limiter.frame_start();
  update_input();
  context->update(fps_limiter.get_delta_time());
  fps_limiter.frame_end();
}

void ae::Engine::update_input() {
  input.poll();
  terminate_on_exit_key();
}

void ae::Engine::terminate_on_exit_key() {
  if (input.check_key(exit_key))
    terminate_loop();
}

void ae::Engine::terminate_loop() {
  exit_loop = in_loop;
}

void ae::Engine::set_context(Context* context) {
  this->context = shared_ptr<Context>(context);
}
