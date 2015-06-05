#include <algorithm>
#include <memory>
#include "renderable.h"
#include "renderable_list.h"

using namespace std;
namespace ae = ascii_engine;

void ae::Renderable_list::add(Renderable* r) {
  add(shared_ptr<Renderable>(r));
}

void ae::Renderable_list::add(shared_ptr<Renderable> r) {
  renderables.push_back(r);
}

void ae::Renderable_list::remove(shared_ptr<Renderable> r) {
  remove(r.get());
}

void ae::Renderable_list::remove(Renderable* r) {
  auto it = find_renderable_from_ptr(r);
  renderables.erase(it);
}

ae::renderables_t::iterator ae::Renderable_list::find_renderable_from_ptr(Renderable* r) {
  auto it = find_if(renderables.begin(), renderables.end(),
    [r](shared_ptr<Renderable> elem) { return elem.get() == r; } );
  return it;
}
