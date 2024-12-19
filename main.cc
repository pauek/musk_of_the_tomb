#include <iostream>
#include "window.hh"
using namespace std;

const int FPS = 60;
const int ZOOM = 2;
const int WIDTH = 320;
const int HEIGHT = 200;

pro2::Sprite sprite = {{0, 1, 2, 1, 0},
                       {1, 2, 6, 2, 1},
                       {2, 6, 7, 6, 2},
                       {1, 2, 6, 2, 1},
                       {0, 1, 2, 1, 0}};

int main() {
    pro2::Window<ZOOM> window(WIDTH, HEIGHT, "Musk of the Tomb");
    int x = WIDTH / 2, y = HEIGHT / 2;

    while (window.next_frame(FPS)) {
        window.clear();
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                window.put_sprite(x + (i - 4) * 10, y + (j - 4) * 10, sprite);
            }
        }

        if (window.is_key_pressed(20)) {
            x--;
        } else if (window.is_key_pressed(19)) {
            x++;
        } else if (window.is_key_pressed(17)) {
            y--;
        } else if (window.is_key_pressed(18)) {
            y++;
        } else if (window.is_key_pressed(27)) {
            exit(1);
        }
    }
}