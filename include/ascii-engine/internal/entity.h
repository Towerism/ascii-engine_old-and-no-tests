/**********************************
 * author: Martin Fracker, Jr.
 * license: GNU GPL
 * * * * * * * * * * * * * * * * *
 * file: entity.h
 * library: ascii-engine
 **********************************/

#ifndef ENTITY_H
#define ENTITY_H

#include "renderable.h"

namespace ascii_engine {
  struct Entity : Renderable {
    Entity() : Entity(0, 0) { }
    Entity(int x, int y) : Entity(x, y, "") { }
    Entity(int x, int y, const string& s) 
      : Renderable(x, y, s), pending_removal(false) { }

    virtual void update(double delta_time) { }

    // if we have been added to a world, we will get removed at some point
    // in the future
    void pend_removal() {
      pending_removal = true;
    }

    bool is_pending_removal() {
      return pending_removal;
    }
  private:
    bool pending_removal;
  };
}

#endif // ENTITY_H
