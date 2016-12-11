#ifndef ISHAPE_HPP
#define ISHAPE_HPP

#include "Ray.hpp"


class IShape {

public:

    IShape() = default;

    /// \fn intersect
    /// \brief show if the Shape is intersecting a ray
    /// \return the argument of the closest point of intersection if there is one, else the constant no_intersection
    /// \warning to test is there is an intersection, compare to no_intersection without any operation !
    /// \arg ray the ray the shape is intersecting
    virtual Scalar intersect(const Ray& ray) const = 0;
};


#endif
