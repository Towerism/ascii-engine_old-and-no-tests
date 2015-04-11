#ifndef RENDERABLE_H
#define RENDERABLE_H

#include <string>

namespace ascii_engine {
  struct Renderable {
    using string = std::string;

    Renderable(int x, int y) : Renderable(x, y, "") { }
    Renderable(int x, int y, string s) : x(x), y(y), graphic(s) { }

    void translate(int delta_x, int delta_y) { x += delta_x; y += delta_y; }

    // setters
    void set_graphic(const string& s) { graphic = s; }
    void set_x(int val) { x = val; }
    void set_y(int val) { y = val; }

    // getters
    const string& get_graphic() const { return graphic; }
    int get_x() const { return x; }
    int get_y() const { return y; }
  private:
    int x, y;
    string graphic;
  };
}

#endif // _ASCII_ENGINE_PRIVATE_
