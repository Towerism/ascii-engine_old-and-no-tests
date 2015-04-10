#ifndef ENGINE_H
#define ENGINE_H

#include <memory>
#include "world.h"

namespace ascii_engine {
  struct Engine {
    Engine(int fps) : target_fps(fps) { }
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
    bool in_loop = false;
    bool exit_loop = false;
    char exit_key = 'q';

    void poll_exit_key();
  };
}

#endif // ENGINE_H
