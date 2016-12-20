#include "Scene.hpp"

void Scene::addShape(IShape* shape) {
    _data.addShape(shape);
}

OpCollision Scene::findCollision(const Ray& ray) const {
    return _data.findCollision(ray);
}
