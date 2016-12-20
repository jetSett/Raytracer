#include "Sphere.hpp"

Sphere::Sphere(Point center, Scalar radius) : _center(center), _radius(radius){}

OpScalar Sphere::intersect(const Ray& ray) const {
    // the equation to solve is : f(t) = (t**2)*(||d||)**2 -2*t*<d, OA> + ||OA||**2 - R**2 = 0
    Scalar scalarProduct = ray.direction.dot(fromTo(ray.origin, _center));
    Scalar squaredNormD = ray.direction.squaredNorm();
    Scalar reduced_discrim = (scalarProduct*scalarProduct - squaredNormD*(  fromTo(ray.origin, _center).squaredNorm() - _radius*_radius   ) );

    if (negative(reduced_discrim))
        return OpScalar();

    if(equal_zero(reduced_discrim)) {
        Scalar t = scalarProduct/squaredNormD;
        return OpScalar(t);
    }

    Scalar t1 = (scalarProduct + sqrt(reduced_discrim))/squaredNormD;
    Scalar t2 = (scalarProduct - sqrt(reduced_discrim))/squaredNormD;

    if (t1 < 0 and t2 < 0)
        return OpScalar();

    if (t1 < 0 || t1 > t2)
        return OpScalar(t2);

    return OpScalar(t1);
}

bool Sphere::contains(Point p) const {
    return equal(fromTo(_center, p).squaredNorm(), _radius*_radius);
}

OpVect3 Sphere::normal(Point p) const {
    if(not contains(p))
        return OpVect3();
    return OpVect3(fromTo(_center, p).normalized());
}
