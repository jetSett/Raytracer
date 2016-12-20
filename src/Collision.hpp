#ifndef COLLISION_HPP
#define COLLISION_HPP

class Collision {

public:

    Collision(Scalar, const Object* const);

    Scalar t;
    const Object* const target;
};

#endif
