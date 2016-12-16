#include "Monochromatic.hpp"

Monochromatic::Monochromatic(uint32_t color): _color(_color) {}

uint32_t Monochromatic::getColor() const {
    return _color;
}
