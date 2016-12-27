#ifndef COLLISION_HPP
#define COLLISION_HPP

#include <Core/Primitives.hpp>
#include <Core/Ray.hpp>
#include <Tools/Optional.hpp>

class Object;

class Collision {

public:

    Collision(Scalar, Ray, const Object*);

    Scalar t;
    Ray ray;
    const Object* target;
};

using OpCollision = Optional<Collision>;

#endif
