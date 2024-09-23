// main.c
#include "fenster.h"

const int width = 1024;
const int height = 768;

void clear(Fenster& f) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            f.px(x, y) = 0;
        }
    }
}

int main() {
    Fenster f(1024, 768, "fenster");
    while (f.loop(600)) {
        f.px(f.x(), f.y()) = 0xff0000;
        if (f.key(' ')) {
            clear(f);
        }
        if (f.key(10)) {
            break;
        }
    }
}