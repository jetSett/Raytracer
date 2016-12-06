#ifndef ISHAPE_HPP
#define ISHAPE_HPP

#include "Ray.hpp"

class IShape {

public:

    IShape() = default;

    /// \fn intersect
    /// \brief show if the Shape is intersecting a ray
    /// \return true if there is an intersection, else false
    /// \arg[in] ray the ray the shape is intersecting
    /// \arg[out] out if there is an intersection, the point of the closest intersection, else this argument is not changed
    virtual bool intersect(const Ray& ray, Point& out) const = 0;
};

#endif
