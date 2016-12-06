#ifndef RAY_HPP
#define RAY_HPP

#include "Primitives.hpp"

class Ray {
public:
    Ray(const Point&, const Vect3&);

    Point origin;
    Vect3 direction;
};

#endif
