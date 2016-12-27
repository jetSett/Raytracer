#include "CollisionManager.hpp"


Color Light_ZBuffer::operator() (const Collision& collision) {
    Scalar t = collision.t / Scalar(Camera::farfarAway);
    Color color = collision.target->getMaterial().color;
    return modulate(color, (1-t)*(1-t));
}

Color Light_Basic::operator()(const Collision& col){
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


CollisionManager::CollisionManager(LightFunctor* l) : _light(l){
}


CollisionManager::~CollisionManager(){
}

Color CollisionManager::getColor(const Collision& c) const{
    return _light->operator()(c);
}
