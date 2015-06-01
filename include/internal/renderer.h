/**********************************
 * author: Martin Fracker, Jr.
 * license: GNU GPL
 * * * * * * * * * * * * * * * * *
 * file: renderer.h
 * library: ascii-engine
 **********************************/

#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include <memory>
#include "renderable.h"
#include "canvas.h"

namespace ascii_engine {
  struct Renderer {
    Renderer(int width, int height) : canvas(width, height) { };
    void add(std::shared_ptr<Renderable> r);
    void remove(std::shared_ptr<Renderable> r) { remove(r.get()); }
    void remove(Renderable* r);

    void render();
  private:
    std::vector<std::shared_ptr<Renderable>> renderables;
    Canvas canvas;
  };
}

#endif // RENDERER_H
