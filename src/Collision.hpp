#ifndef COLLISION_HPP
#define COLLISION_HPP

#include "Primitives.hpp"
#include "Optional.hpp"

class IShape;

class Collision {

public:

    Collision(Scalar, const IShape*);

    Scalar t;
    const IShape* target;
};

using OpCollision = Optional<Collision>;

#endif
