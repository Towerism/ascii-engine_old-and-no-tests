#ifndef RENDERABLE_REMOVER_H
#define RENDERABLE_REMOVER_H

#include <vector>
#include <memory>

namespace ascii_engine {

  struct Renderable_list;
  struct Renderable;
  typedef std::vector<std::shared_ptr<Renderable>> renderables_t;

  struct Renderable_remover {

    void attach_renderable_list(Renderable_list* renderable_list);

    void remove(std::shared_ptr<Renderable> r);
    void remove(Renderable* r);

  private:

    std::vector<Renderable_list*> lists;

  };
}

#endif // RENDERABLE_REMOVER_H
