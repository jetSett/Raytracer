#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "IShape.hpp"
#include "Primitives.hpp"

class Sphere : public IShape {
    
public:

    Sphere(Point, Scalar);
    
    /// \fn intersect
    /// \brief get the intersection point with the Ray
    virtual Point intersect(const Ray&) const override;
    
private:

    Point _center;
    Scalar _radius;
    
};

#endif
