#ifndef COLLISION_HPP
#define COLLISION_HPP

#include <Core/Primitives.hpp>
#include <Tools/Optional.hpp>

class Object;

class Collision {

public:

    Collision(Scalar, const Object*);

    Scalar t;
    const Object* target;
};

using OpCollision = Optional<Collision>;

#endif
