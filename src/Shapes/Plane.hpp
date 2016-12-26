#ifndef PLANE_HPP
#define PLANE_HPP

#include <Core/IShape.hpp>
#include <Core/Primitives.hpp>



///\class Plane
/// \brief represent a plane
class Plane : public IShape {
public:
    Plane(Point origin, Vect3 normal);
    virtual bool contains(Point p) const override;
    virtual OpVect3 normal(Point p) const override;
    virtual OpScalar intersect(const Ray& ray) const override;
private:
    Point _origin;
    Vect3 _normal;
};

#endif
