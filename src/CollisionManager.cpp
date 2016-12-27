#include "CollisionManager.hpp"

Light_ZBuffer CollisionManager::zbuffer;
Light_Basic CollisionManager::basic;

Color Light_ZBuffer::operator() (const Collision& collision) const {
    Scalar t = collision.t / Scalar(Camera::farfarAway);
    Color color = collision.target->getMaterial().color;
    return modulate(color, (1-t)*(1-t));
}

Color Light_Basic::operator()(const Collision& col) const {
    const Point& p = col.ray.getPoint(col.t);
    Scalar t = 0.;
    col.target->getShape().normal(p).ifelseOp([&](Vect3 n){
        t = std::abs(n.dot(col.ray.direction.normalized()));
    },
    [&](){
        t = 1.;
    });

    Color color = col.target->getMaterial().color;
    return modulate(color, t);
}
