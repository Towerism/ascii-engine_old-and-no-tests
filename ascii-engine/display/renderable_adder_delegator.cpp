#include <algorithm>
#include "renderable.h"
#include "renderable_adder.h"
#include "renderable_adder_delegator.h"
#include "renderable_list.h"

namespace ae = ascii_engine;

using std::shared_ptr;

void ae::Renderable_adder_delegator::attach_delegate(Renderable_adder* delegate) {
  delegates.push_back(delegate);
}

void ae::Renderable_adder_delegator::add(Renderable* r) {
  add(shared_ptr<Renderable>(r));
}

void ae::Renderable_adder_delegator::add(shared_ptr<Renderable> r) {
  r->attach_delegator(this);
  add_to_lists(r);
}

void ae::Renderable_adder_delegator::add_to_lists(shared_ptr<Renderable> r) {
  for (Renderable_adder* delegate : delegates)
    delegate->add(r);
}

void ae::Renderable_adder_delegator::remove(shared_ptr<Renderable> r) {
  remove(r.get());
}

void ae::Renderable_adder_delegator::remove(Renderable* r) {
  for (Renderable_adder* delegate : delegates)
    delegate->remove(r);
}
