#ifndef CANVAS_H
#define CANVAS_H

#include "screen_buffer.h"

namespace ascii_engine {
    struct Canvas {
        Canvas(int width, int height, char val = ' ') : 
            buffer(width, height, val) { }

        void draw(int x, int y, char c) { buffer.set_char(x, y, c); }
        void draw(int x, int y, const std::string& s);

        void refresh() { buffer.flush(); }

        // getters
        const Screen_buffer get_buffer() const { return buffer; }
    private:
        Screen_buffer buffer;
    };
}

#endif // CANVAS_H
