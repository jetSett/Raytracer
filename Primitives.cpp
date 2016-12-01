#include "Primitives.hpp"

/// \def origin
/// \brief Origin
///
/// Constant point at coordinates (0, 0, 0)
const Point origin(Scalar(0), Scalar(0), Scalar(0));

/// \fn Point(Scalar x, Scalar y, Scalar z)
/// \brief Constructor for Point
/// \param x x coordinate
/// \param y y coordinate
/// \param z z coordinate
///
/// Copy constructor is also available
Point(Scalar _x, Scalar _y, Scalar _z):
    x(_x), y(_y), z(_z)
    {}
    
/// \fn void operator+=(const Vect3& direction)
/// \brief Translate point in direction
/// \param direction direction of translation
void operator+=(const Vect3& direction) {
    x += direction(0);
    y += direction(1);
    z += direction(2);
}

/// \fn Vect3 fromTo(Point from, Point to)
/// \brief construct a Vect3 AB which connects two points
/// \param from Point A
/// \param to Point B
/// \return the Vect3 constructed
Vect3 fromTo(Point from, Point to) {
    return Vect3(to.x - from.x, to.y - from.y, to.z - from.z);
}

/// \fn Point operator+(const Point& from, const Vect3& direction)
/// \brief return the translation of a point A in direction d
/// \param from point A
/// \param direction direction d of translation
/// \param the Point constructed
Point operator+(const Point& from, const Vect3& direction) {
    Point temp(from);
    temp += direction;
    return temp;
}
