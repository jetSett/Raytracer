#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "IShape.hpp"
#include "Primitives.hpp"


/// \class Sphere
/// \brief represent a Sphere
class Sphere : public IShape {

public:
    Sphere(Point, Scalar);
    virtual bool contains(Point p) const override;
    virtual OpVect3 normal(Point p) const override;
protected:
    /// \fn intersect
    /// \brief get the intersection point with ray
    virtual OpScalar intersect(const Ray& ray) const override;
private:
    Point _center;
    Scalar _radius;

};

#endif
