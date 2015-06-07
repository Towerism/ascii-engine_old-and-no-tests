#ifndef RENDERABLE_H
#define RENDERABLE_H

#include <string>

namespace ascii_engine {

  struct Renderable_adder_delegator;

  struct Renderable {

    Renderable(int x, int y);
    Renderable(int x, int y, std::string s);

    void translate(int delta_x, int delta_y);

    virtual void update(double delta_time) { }

    void attach_delegator(Renderable_adder_delegator* delegator);
    void set_graphic(const std::string& s);

    const std::string& get_graphic() const;
    int get_x() const;
    int get_y() const;

  protected:

    int x, y;
    std::string graphic;

    Renderable_adder_delegator* delegator;
  };
}

#endif // _ASCII_ENGINE_PRIVATE_
