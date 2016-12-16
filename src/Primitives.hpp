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


/// \def EPSILON
/// \brief a little value used to determine if something is equal to zero
extern const Scalar EPSILON;

/// \fn equal_zero
/// \brief test if a Scalar is very near from zero
bool equal_zero(Scalar);

/// \fn negative
/// \brief test if a scalar is negative (< -EPSILON)
bool negative(Scalar);

/// \fn positive
/// \brief test if a scalar is positive (> -EPSILON)
bool positive(Scalar);

/// \fn equal
/// \brief test if two Scalar are equal (modulo EPSILON)
bool equal(Scalar, Scalar);

/// \struct Point Primitives.hpp
/// \brief Point in 3D space
struct Point {

    Point() = default;

    /// \fn Point(Scalar x, Scalar y, Scalar z)
    /// \brief Constructor for Point
    /// \param x x coordinate
    /// \param y y coordinate
    /// \param z z coordinate
    /// \note Copy constructor is also available
    Point(Scalar, Scalar, Scalar);
    Point(const Point&) = default;
    Point& operator=(const Point&) = default;



    /// \fn void operator+=(const Vect3& direction)
    /// \brief Translate point in direction
    /// \param direction direction of translation
    void operator+=(const Vect3&);

    Scalar x;
    Scalar y;
    Scalar z;
};

/// \fn Point operator+(const Point& from, const Vect3& direction)
/// \brief return the translation of a point A in direction d
/// \param from point A
/// \param direction direction d of translation
/// \param the Point constructed
Point operator+(const Point&, const Vect3&);



/// \fn Vect3 fromTo(Point from, Point to)
/// \brief construct a Vect3 AB which connects two points
/// \param from Point A
/// \param to Point B
/// \return the Vect3 constructed
Vect3 fromTo(Point, Point);


/// \def origin
/// \brief Constant point at coordinates (0, 0, 0)
extern const Point absolut_origin;


///\def no_intersection
///\brief a constant returned if there is no intersection
extern const Scalar no_intersection;

#endif
