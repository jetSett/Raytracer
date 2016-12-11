#include "Triangle.hpp"

Triangle::Triangle(Point v1, Point v2, Point v3){

}

// implementing the Moller Trumbore algorithm, from the wikipedia page
Scalar Triangle::intersection(const Ray& ray) const {
    Vect3 e1 = fromTo(_v1, _v2), e2 = fromTo(_v1, _v3);

    const Vect3& D = ray.direction;

    Vect3 P = D.cross(e2);

    Scalar det = e1.dot(P);
    if(equal_zero(det))
        return no_intersection;

    Vect3 T = fromTo(_v1, ray.origin);
    Scalar u = T.dot(P)/det;
    if(negative(u) or u > 1)
        return no_intersection;

    Vect3 Q = T.cross(e1);

    Scalar v = D.dot(Q)/det;
    if(negative(v) or u+v > 1)
        return no_intersection;

    Scalar t = e2.dot(Q)/det;
    if(positive(t))
        return t;

    return no_intersection;
}
