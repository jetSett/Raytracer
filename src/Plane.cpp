#include "Plane.hpp"

Plane::Plane(Point p, Vect3 n) : _origin(p), _normal(n){
}

Scalar Plane::intersect(const Ray& ray) const{
    Scalar prod = _normal.dot(ray.direction);
    if(equal_zero(prod)){
        return no_intersection;
    }else{
        return _normal.dot(fromTo(_origin, ray.origin))/prod;
    }
}

bool Plane::contains(Point p) const{
    return not equal_zero(_normal.dot(fromTo(_origin, p)));
}

Vect3 Plane::normal(Point p) const{
    if (not contains(p)){
        return Vect3(0, 0, 0);
    }
    return _normal.normalized();
}
