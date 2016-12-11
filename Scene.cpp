#include "Scene.hpp"

Scalar Scene::intersect(const Ray& ray) const {
    Scalar tMax = no_intersection;
    for (const auto& shape : _shapes) {
        Scalar t = shape->intersect(ray);
        if (t == no_intersection)
            continue ;
        if (tMax == no_intersection || t < tMax)
                tMax = t;
    }
    return tMax;
}
