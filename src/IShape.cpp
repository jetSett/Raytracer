#include "IShape.hpp"

OpCollision IShape::findCollision(const Ray& ray) const {
    OpScalar t = intersect(ray);
    return t.ifelseOpReturn<OpCollision>(
        [&](Scalar t){ return OpCollision(Collision(t, this)); },
        [&]()         { return OpCollision();                  });
}
