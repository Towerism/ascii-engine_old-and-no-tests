/**********************************
 * author: Martin Fracker, Jr.
 * license: GNU GPL
 * * * * * * * * * * * * * * * * *
 * file: world.h
 * library: ascii-engine
 **********************************/

#ifndef WORLD_H
#define WORLD_H

#include <memory>
#include <vector>
#include <ascii-engine/display/renderer.h>
#include <ascii-engine/display/renderable_list.h>

namespace ascii_engine {

  struct World : Renderable_list {

    virtual void update(double delta_time);

  private:

    void update_renderables(double delta_time);
  };
}

#endif // WORLD_H
