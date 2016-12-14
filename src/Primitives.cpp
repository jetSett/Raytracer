#include "Primitives.hpp"



const Point absolut_origin(Scalar(0), Scalar(0), Scalar(0));
const Scalar no_intersection = -1;
const Scalar EPSILON = 0.000001;

bool equal_zero(Scalar s){
    return (s < EPSILON) && (s> -EPSILON);
}

bool negative(Scalar s){
    return s < (-EPSILON);
}

bool positive(Scalar s){
    return s > EPSILON;
}

bool equal(Scalar a, Scalar b){
    return equal_zero(a-b);
}

Point::Point(Scalar _x, Scalar _y, Scalar _z):
    x(_x), y(_y), z(_z)
    {}

void Point::operator+=(const Vect3& direction) {
    x += direction(0);
    y += direction(1);
    z += direction(2);
}


Vect3 fromTo(Point from, Point to) {
    return Vect3(to.x - from.x, to.y - from.y, to.z - from.z);
}


Point operator+(const Point& from, const Vect3& direction) {
    Point temp(from);
    temp += direction;
    return temp;
}
