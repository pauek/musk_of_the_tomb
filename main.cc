#include <iostream>
#include "window.hh"
using namespace std;

const int ZOOM = 3;
const int WINDOW_WIDTH = 320;
const int WINDOW_HEIGHT = 200;
const int FPS = 60;

int main() {
    pro2::Window<ZOOM> window(WINDOW_WIDTH, WINDOW_HEIGHT, "Musk of the Tomb");

    while (window.next_frame(FPS)) {
        const int x = window.mouse_x();
        const int y = window.mouse_y();
        if (window.mouse_button() == 1) {
            window.pixel(x, y) = 0xff0000;
        }
        if (window.is_key_pressed(' ')) {
            window.clear();
        }
        if (window.is_key_pressed(27)) {
            exit(1);
        }
        window.put_frame();
    }
}