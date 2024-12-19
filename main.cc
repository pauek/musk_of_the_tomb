#include <iostream>
#include "game.hh"

int main() {
    pro2::Window window(320, 200, "Musk of the Tomb");
    while (window.loop(60)) {
        const int x = window.mouse_x();
        const int y = window.mouse_y();
        if (window.mouse_button() == 1) {
            window.pixel(x, y) = 0xff0000;
        }
        if (window.key(' ')) {
            window.clear();
        }
        window.put_frame();
    }
}