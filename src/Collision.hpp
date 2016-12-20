#ifndef COLLISION_HPP
#define COLLISION_HPP

#include "Primitives.hpp"
#include "Optional.hpp"

class Object;

class Collision {

public:

    Collision(Scalar, const Object*);

    Scalar t;
    const Object* target;
};

using OpCollision = Optional<Collision>;

#endif
