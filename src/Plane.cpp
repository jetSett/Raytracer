#include "Plane.hpp"

Plane::Plane(Point p, Vect3 n) : _origin(p), _normal(n){
}

OpScalar Plane::intersect(const Ray& ray) const{
    Scalar prod = _normal.dot(ray.direction);
    if(equal_zero(prod)){
        return OpScalar();
    }else{
        return OpScalar(_normal.dot(fromTo(_origin, ray.origin))/prod);
    }
}

bool Plane::contains(Point p) const{
    return not equal_zero(_normal.dot(fromTo(_origin, p)));
}

OpVect3 Plane::normal(Point p) const{
    if (not contains(p)){
        return OpVect3();
    }
    return OpVect3(_normal.normalized());
}
