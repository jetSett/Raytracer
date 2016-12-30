#include <Tools/Debug.hpp>
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
        throw std::exception();
    });

    Color color = col.target->getMaterial().color;
    return modulate(color, t);
}

Light_Multi::Light_Multi(LampSet s) : _lamps(s){
}

Color Light_Multi::operator()(const Collision& collision){
    const Point& p = collision.ray.getPoint(collision.t);
    unsigned n = _lamps.size();
    Scalar t = 0;
    for(Lamp* l : _lamps){
        l->point_of_view(p).ifOp([&](Vect3 dir){
            collision.target->getShape().normal(p).ifelseOp([&](Vect3 n){

                if(negative(dir.dot(n)*fromTo(p, collision.ray.origin).dot(n))){
                    t += std::abs(n.dot(dir.normalized()));

                }

            },
            [&](){
                throw std::exception();
            });
        });
    }
    t /= n;
    Color color = collision.target->getMaterial().color;
    return modulate(color, t);
}

CollisionManager::CollisionManager(LightFunctor* l) : _light(l){
}

CollisionManager::~CollisionManager(){
}

Color CollisionManager::getColor(const Collision& c) const{
    return _light->operator()(c);
}
