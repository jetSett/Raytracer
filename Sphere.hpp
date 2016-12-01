#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "IShape.hpp"

class Sphere : public IShape {
    
public:

    Sphere(Point, Scalar);
    virtual Point intersect(const Ray&) const override;
    
private:

    Point center;
    Scalar radius;
    
};

#endif
