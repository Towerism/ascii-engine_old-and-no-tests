#include <algorithm>
#include "renderable.h"
#include "renderable_remover.h"
#include "renderable_list.h"

namespace ae = ascii_engine;
using namespace std;

void ae::Renderable_remover::attach_renderable_list(Renderable_list* renderable_list) {
  lists.push_back(renderable_list);
}

void ae::Renderable_remover::remove(shared_ptr<Renderable> e) {
  remove(e.get());
}

void ae::Renderable_remover::remove(Renderable* e) {
  for (Renderable_list* list : lists)
    list->remove(e);
}
