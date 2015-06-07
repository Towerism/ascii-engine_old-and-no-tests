#ifndef ENGINE_H
#define ENGINE_H

#include <memory>
#include <ascii-engine/timing/framerate_limiter.h>
#include <ascii-engine/input/input_buffer.h>
#include "context.h"

namespace ascii_engine {

  struct Engine {

    Engine(int target_fps) :
      fps_limiter(target_fps),
      input(Input_buffer::get()) { }

    void game_loop();

    void set_context(Context* context);
    void set_exit_key(char key) { exit_key = key; }

  private:

    std::shared_ptr<Context> context;

    Framerate_limiter fps_limiter;
    Input_buffer& input;

    bool in_loop = false;
    bool exit_loop = false;
    char exit_key = 'q';

    void update_frame();
    void update_input();
    void terminate_on_exit_key();
    void terminate_loop();
  };
}

#endif // ENGINE_H
