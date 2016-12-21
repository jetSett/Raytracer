#include "Scene.hpp"

#include <iostream>

void Scene::addObject(Object* object) {
    _data.push_back(object);
}

OpCollision Scene::findCollision(const Ray& ray) const {
    OpCollision closest;
    for (const auto& object : _data) {
        OpCollision collision = object->findCollision(ray);
        collision.ifOp([&](const Collision& collision){
            closest.ifelseOp([&](Collision& closest){
                if (closest.t > collision.t)
                    closest = collision;
            },[&](){
                closest.assign(collision);
            });
        });
    }
    return closest;
}
