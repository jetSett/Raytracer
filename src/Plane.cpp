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
