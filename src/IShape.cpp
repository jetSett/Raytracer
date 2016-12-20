#include "IShape.hpp"

OpCollision getCollision(const Ray& ray) const {
    return OpCollision(Collision(intersect(ray), this));
}
