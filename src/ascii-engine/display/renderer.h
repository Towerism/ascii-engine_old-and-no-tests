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
#include "renderable_list.h"
#include "canvas.h"

namespace ascii_engine {

  struct Renderer : Renderable_list {

    Renderer(int width, int height) : canvas(width, height) { };

    void render();

  private:

    Canvas canvas;

    void draw_renderables();
  };

}

#endif // RENDERER_H
