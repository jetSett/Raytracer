#include "Collection.hpp"

void Collection::addShape(IShape* shape) {
    _shapes.push_back(shape);
}

Scalar Collection::intersect(const Ray& ray) const {
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
