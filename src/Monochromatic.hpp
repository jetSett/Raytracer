#ifndef MONOCHROMATIC_HPP
#define MONOCHROMATIC_HPP

#include "IMaterial.hpp"

class Monochromatic : public IMaterial {

public:

    Monochromatic(uint32_t);

    virtual uint32_t getColor() const override;

private:

    uint32_t _color;
};

#endif
