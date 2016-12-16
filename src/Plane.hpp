#ifndef PLANE_HPP
#define PLANE_HPP

#include "IShape.hpp"
#include "Primitives.hpp"



///\class Plane
/// \brief represent a plane
class Plane : public IShape {
public:
    Plane(Point origin, Vect3 normal);
    virtual Scalar intersect(const Ray& ray) const override;
    virtual bool contains(Point p) const override;
    virtual Vect3 normal(Point p) const override;
private:
    Point _origin;
    Vect3 _normal;
};

#endif
