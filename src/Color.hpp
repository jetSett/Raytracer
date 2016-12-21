#ifndef COLOR_HPP
#define COLOR_HPP

#include <cstdint>

#include "Primitives.hpp"

class Color {
public:
    Color(uint8_t, uint8_t, uint8_t, uint8_t alpha = static_cast<uint8_t>(0xFF));
    Color(uint32_t);
    uint32_t code() const;
    void operator+=(Color);
    void modulate(Scalar);
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
    static const Color Red;
    static const Color Green;
    static const Color Blue;
    static const Color Yellow;
    static const Color Cyan;
    static const Color Magenta;
    static const Color White;
    static const Color Black;
};

Color operator+(Color, Color);
Color modulate(Color, Scalar);

#endif
