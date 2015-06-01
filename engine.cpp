/**********************************
 * author: Martin Fracker, Jr.
 * license: GNU GPL
 * * * * * * * * * * * * * * * * *
 * file: engine.cpp
 * library: ascii-engine
 **********************************/

#include "engine.h"
#include "framerate_limiter.h"
#include "input_handler.h"

namespace ae = ascii_engine;
using namespace std;

void ae::Engine::game_loop() {
  using Input_handler = ae::Input_handler;
  Framerate_limiter fps_limiter(target_fps);
  Input_handler& input = Input_handler::get();
  in_loop = true;
  while (!exit_loop) {
    fps_limiter.frame_start();
    input.poll();
    poll_exit_key();
    world->update(fps_limiter.get_delta_time());
    fps_limiter.frame_end();
  }
}

void ae::Engine::poll_exit_key() {
  if (ae::Input_handler::get().check_key(exit_key)) {
    terminate_loop();
  }
}
