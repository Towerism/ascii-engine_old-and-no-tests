#ifndef RENDERABLE_H
#define RENDERABLE_H

#include <string>
#include <ascii-engine/component/component.h>

namespace ascii_engine {

  struct Renderable_adder_delegator;

  struct Renderable : Component {

    Renderable();
    Renderable(std::string s);

    virtual void update() override { }

    void attach_delegator(Renderable_adder_delegator* delegator);
    void set_graphic(const std::string& s);

    const std::string& get_graphic() const;

  private:

    std::string graphic;

    Renderable_adder_delegator* delegator;
  };
}

#endif // _ASCII_ENGINE_PRIVATE_
