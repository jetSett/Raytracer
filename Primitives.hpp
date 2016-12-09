/// \file Primitives.hpp
/// \brief Define basic geometric primitives : Scalar, Vect3, Point
/// \author Louis.B

#ifndef PRIMITIVES_HPP
#define PRIMITIVES_HPP

#include "Eigen/Dense"

/// \struct Scalar Primitives.hpp
/// \brief Scalar type
///
/// typedef on float or double
using Scalar = double;

/// \struct Vect3 Primitives.hpp
/// \brief Vector in 3D space
///
/// See Eigen::Matrix<Scalar, 3, 1> for more documentation
using Vect3 = Eigen::Matrix<Scalar, 3, 1>;

/// \struct Point Primitives.hpp
/// \brief Point in 3D space
struct Point {

    Point() = default;
    Point(Scalar, Scalar, Scalar);
    Point(const Point&) = default;
    Point& operator=(const Point&) = default;

    void operator+=(const Vect3&);

    Scalar x;
    Scalar y;
    Scalar z;
};

Point operator+(const Point&, const Vect3&);
Vect3 fromTo(Point, Point);

extern const Point absolut_origin;

#endif
