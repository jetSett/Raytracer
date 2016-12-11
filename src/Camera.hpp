#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "Primitives.hpp"

/// \class Camera
/// \brief A class to manipulate cameras
class Camera {

public:

    /// \fn Camera(const Point&, const Vect3&, Scalar, Scalar)
    /// \brief construct a new Camera
    /// param position position of camera
    /// param direction direction of view, focal plan is normal to it
    /// param gammaWidth ratio along width axis
    /// param gammaHeight ratio along height axis
    Camera(const Point& point, const Vect3& direction, Scalar gammaWidth, Scalar gammaHeight);

    Ray getRay(unsigned int, unsigned int);

private:

    Point _position;
    Vect3 _normal;
    Scalar _gammaWidth;
    Scalar _gammaHeight;
};

#endif
