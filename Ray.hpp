#ifndef RAY_HPP
#define RAY_HPP

#include "Primitives.hpp"

struct Ray {
    
    Ray(Point, Vect3);
    
    Point departure;
    Vect3 direction;
};

#endif
