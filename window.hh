#ifndef GAME_HH
#define GAME_HH

#include "fenster.h"

namespace pro2 {

template <int ZOOM = 3>
class Window {
    const uint16_t _width, _height;
    uint32_t* _pre;
    int64_t _last_time;

    struct fenster _fenster;

   public:
    Window(const uint16_t w, const uint16_t h, const char* title)
        : _width(w), _height(h), _fenster{title, ZOOM * w, ZOOM * h} {
        _fenster.buf = new uint32_t[w * ZOOM * h * ZOOM];
        _pre = new uint32_t[_width * _height];
        _last_time = fenster_time();
        fenster_open(&_fenster);
    }

    ~Window() {
        fenster_close(&_fenster);
        delete[] _fenster.buf;
        delete[] _pre;
    }

    inline uint32_t& pixel(int x, int y) { return _pre[y * _width + x]; }

    bool is_key_pressed(int c) {
        return c >= 0 && c < 128 ? _fenster.keys[c] : false;
    }

    int mouse_x() const { return _fenster.x / ZOOM; }
    int mouse_y() const { return _fenster.y / ZOOM; }
    int mouse_button() const { return _fenster.mouse; }
    int modifier_keys() const { return _fenster.mod; }

    void clear() {
        uint32_t* p = _pre;
        const uint32_t* end = _pre + _width * _height;
        while (p < end) {
            *p++ = 0;
        }
    }

    void put_frame() {
        uint32_t *ppre, *pbuf[ZOOM];
        const size_t num_pixels = _width * _height;
        for (size_t j = 0; j < _height; j++) {
            ppre = _pre + j * _width;
            for (uint8_t z = 0; z < ZOOM; z++) {
                pbuf[z] = _fenster.buf + (ZOOM * j + z) * _fenster.width;
            }
            for (size_t i = 0; i < _width; i++) {
                const uint32_t color = *ppre++;
                for (uint8_t z = 0; z < ZOOM; z++) {
                    for (uint8_t k = 0; k < ZOOM; k++) {
                        *pbuf[z]++ = color;
                    }
                }
            }
        }
    }

    bool next_frame(const int fps) {
        int64_t now = fenster_time();
        if (now - _last_time < 1000 / fps) {
            fenster_sleep(now - _last_time);
        }
        _last_time = now;
        return fenster_loop(&_fenster) == 0;
    }
};

};  // namespace pro2

#endif