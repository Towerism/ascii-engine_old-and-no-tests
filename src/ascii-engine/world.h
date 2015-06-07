#ifndef WORLD_H
#define WORLD_H

#include <ascii-engine/display/renderable_list.h>

namespace ascii_engine {

  struct World : Renderable_list {

    virtual void update(double delta_time);

  private:

    void update_renderables(double delta_time);
  };
}

#endif // WORLD_H
