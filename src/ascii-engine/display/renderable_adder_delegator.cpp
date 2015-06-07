#include <algorithm>
#include "renderable_adder.h"
#include "renderable_adder_delegator.h"
#include "renderable_list.h"

namespace ae = ascii_engine;
using namespace std;

void ae::Renderable_adder_delegator::attach(Renderable_adder* renderable_adder) {
  adders.push_back(renderable_adder);
}

void ae::Renderable_adder_delegator::add(Renderable* r) {
  add(shared_ptr<Renderable>(r));
}

void ae::Renderable_adder_delegator::add(shared_ptr<Renderable> r) {
  r->attach_adder(this);
  add_to_lists(r);
}

void ae::Renderable_adder_delegator::add_to_lists(shared_ptr<Renderable> r) {
  for (Renderable_adder* adder : adders)
    adder->add(r);
}

void ae::Renderable_adder_delegator::remove(shared_ptr<Renderable> r) {
  remove(r.get());
}

void ae::Renderable_adder_delegator::remove(Renderable* r) {
  for (Renderable_adder* adder : adders)
    adder->remove(r);
}
