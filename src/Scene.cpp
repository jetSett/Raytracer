#include "Scene.hpp"

void Scene::addShape(IShape* shape) {
    _data.addShape(shape);
}

Scalar Scene::findIntersection(const Ray& ray) const {
    return _data.intersect(ray);
}
