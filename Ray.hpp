#ifndef RAY_HPP
#define RAY_HPP

#include "Primitives.hpp"

class Ray {
public:
    Ray(const Point&, const Vect3&);

    /// \fn getPoint
    /// \brief return the point of parameter t on the ray
    /// \return the point (origin + t*direction)
    /// \param t the parameter of the point wanted
    Point getPoint(Scalar t) const;

    Point origin;
    Vect3 direction;
};

#endif
