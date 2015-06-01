/**********************************
 * author: Martin Fracker, Jr.
 * license: GNU GPL
 * * * * * * * * * * * * * * * * *
 * file: engine.h
 * library: ascii-engine
 **********************************/

#ifndef ENGINE_H
#define ENGINE_H

#include <memory>
#include <ascii-engine/timing/framerate_limiter.h>
#include <ascii-engine/input/input_handler.h>
#include "world.h"

namespace ascii_engine {

  struct Engine {

    Engine(int fps) : target_fps(fps), fps_limiter(target_fps),
                      input(Input_handler::get()) { }

    void game_loop();
    void terminate_loop() { exit_loop = in_loop; }

    // getters
    char get_exit_key() const { return exit_key; }

    // setters
    void set_world(std::shared_ptr<World> w) { world = w; }
    void set_exit_key(char key) { exit_key = key; }

  private:

    std::shared_ptr<World> world;

    int target_fps;
    Framerate_limiter fps_limiter;
    Input_handler& input;

    bool in_loop = false;
    bool exit_loop = false;
    char exit_key = 'q';

    void update_frame();
    void update_input();
    void terminate_on_exit_key();
  };
}

#endif // ENGINE_H
