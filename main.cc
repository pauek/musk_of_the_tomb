// main.c
#include "fenster.h"

const int W = 1024;
const int H = 768;

int main()
{
    Fenster f(W, H, "fenster");
    while (f.loop())
    {
        f.px(f.x(), f.y()) = 0xff0000;
    }
}