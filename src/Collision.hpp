#ifndef COLLISION_HPP
#define COLLISION_HPP

#include "Primitives.hpp"
#include "Optional.hpp"
#include "IShape.hpp"

class Collision {

public:

    Collision(Scalar, const IShape* const);

    Scalar t;
    const IShape* const target;
};

using OpCollision = Optional<Collision>;

#endif
