#ifndef IMATERIAL_HPP
#define IMATERIAL_HPP

#include <cstdint>

class IMaterial {

public:

    IMaterial() = default;

    virtual uint32_t getColor() const = 0;

private:

};

#endif
