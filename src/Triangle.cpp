#include "Triangle.hpp"

Triangle::Triangle(Point v1, Point v2, Point v3) : _v1(v1), _v2(v2), _v3(v3){

}

// implementing the Moller Trumbore algorithm, from the wikipedia page
Scalar Triangle::intersect(const Ray& ray) const {
    Vect3 e1 = fromTo(_v1, _v2), e2 = fromTo(_v1, _v3);

    const Vect3& D = ray.direction;

    Vect3 P = D.cross(e2);

    Scalar det = e1.dot(P);
    if(equal_zero(det)){
        return no_intersection;
    }

    Vect3 T = fromTo(_v1, ray.origin);
    Scalar u = T.dot(P)/det;
    if(negative(u) or u > 1){
        return no_intersection;
    }

    Vect3 Q = T.cross(e1);

    Scalar v = D.dot(Q)/det;
    if(negative(v) or u+v > 1){
        return no_intersection;
    }

    Scalar t = e2.dot(Q)/det;
    if(positive(t))
        return t;

    return no_intersection;
}

bool good_side(Point M, Point A, Point B){
    return positive( (fromTo(A, M).cross(fromTo(A, M))).dot( fromTo(A, M).cross(fromTo(A, B)) ) );
}

bool Triangle::contains(Point M) const{
    return  good_side(M, _v1, _v3) and good_side(M, _v3, _v2) and good_side(M, _v2, _v1);
}

Vect3 Triangle::normal(Point M) const{
    if(not contains(M)){
        return Vect3(0, 0, 0);
    }
    return (fromTo(_v1, _v2).cross( fromTo(_v1, _v3) ) ).normalized();
}
