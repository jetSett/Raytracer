#include "Collection.hpp"

void Collection::addShape(IShape* shape) {
    _shapes.push_back(shape);
}

OpCollision Collection::findCollision(const Ray& ray) const {
    OpCollision closest;
    for (const auto& shape : _shapes) {
        shape->findCollision(ray).ifOp([&](const Collision& collision){ //si il y a intersection, on effectue le morceau de code
            closest.ifelseOp([&](Collision& closest){
                if(closest.t > collision.t)
                    closest = collision;
            }, [&](){
                closest.assign(collision);
            });
        });
    }
    return closest;
}
