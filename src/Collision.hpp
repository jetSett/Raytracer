#ifndef COLLISION_HPP
#define COLLISION_HPP

#include "Primitives.hpp"
#include "Optional.hpp"

class Collision {

public:

    Collision(Scalar, const Object* const);

    Scalar t;
    const Object* const target;
};

using OpCollision = Optional<Collision>;

#endif
