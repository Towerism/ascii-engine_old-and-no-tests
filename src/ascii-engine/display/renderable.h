/**********************************
 * author: Martin Fracker, Jr.
 * license: GNU GPL
 * * * * * * * * * * * * * * * * *
 * file: renderable.h
 * library: ascii-engine
 **********************************/

#ifndef RENDERABLE_H
#define RENDERABLE_H

#include <string>
#include "renderable_remover.h"

namespace ascii_engine {
  struct Renderable {
    using string = std::string;

    Renderable(int x, int y) : Renderable(x, y, "") { }
    Renderable(int x, int y, string s) : x(x), y(y), graphic(s) { }

    void translate(int delta_x, int delta_y) { x += delta_x; y += delta_y; }

    virtual void update(double delta_time) { }

    void attach_remover(Renderable_remover& remover) {
      this->remover = &remover;
    }

    void set_graphic(const string& s) { graphic = s; }

    const string& get_graphic() const { return graphic; }
    int get_x() const { return x; }
    int get_y() const { return y; }

  protected:

    int x, y;
    string graphic;

    Renderable_remover* remover;
  };
}

#endif // _ASCII_ENGINE_PRIVATE_
