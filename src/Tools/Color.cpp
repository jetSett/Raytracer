#include "Color.hpp"

const Color Color::Red(0xFF, 0, 0);
const Color Color::Green(0, 0xFF, 0);
const Color Color::Blue(0, 0, 0xFF);
const Color Color::Yellow = Color::Red + Color::Green;
const Color Color::Cyan = Color::Green + Color::Blue;
const Color Color::Magenta = Color::Blue + Color::Red;
const Color Color::White = Color::Red + Color::Green + Color::Blue;
const Color Color::Black(0, 0, 0);

Color::Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha):
    r(red), g(green), b(blue), a(0xFF) {}

Color::Color(uint32_t bytes):
    r(bytes&0xFF), g((bytes>>1)&0xFF), b((bytes>>2)&0xFF), a((bytes>>3)&0xFF) {}

uint32_t Color::code() const {
    return r | (g << 8) | (b << 16) | (a << 24);
}

void Color::operator+=(Color c) {
    r += c.r;
    g += c.g;
    b += c.b;
    a += c.a;
}

void Color::modulate(Scalar t) {
    r = static_cast<uint8_t>(Scalar(r) * t);
    g = static_cast<uint8_t>(Scalar(g) * t);
    b = static_cast<uint8_t>(Scalar(b) * t);
}

Color operator+(Color left, Color right) {
    left += right;
    return left;
}

Color modulate(Color color, Scalar t) {
    Color temp(color);
    temp.modulate(t);
    return temp;
}
