#include "IShape.hpp"

OpCollision findCollision(const Ray& ray) const {
    OpScalar t = intersect(ray);
    return t.ifelseOpReturn<OpCollision>(
        [&](Scalar& t){ return OpCollision(Collision(, this)); },
        [&]()         { return OpCollision();                  }
}
