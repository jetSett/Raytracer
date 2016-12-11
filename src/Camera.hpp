#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "Primitives.hpp"
#include "Ray.hpp"

/// \class Camera
/// \brief A class to manipulate cameras
class Camera {

public:

    /// \fn Camera(const Point&, const Vect3&, Scalar, Scalar)
    /// \brief construct a new Camera
    /// param position position of camera
    /// param direction direction of view, focal plan is normal to it
    /// param width width in pixels
    /// param height height in pixels
    /// param gammaWidth ratio along width axis
    /// param gammaHeight ratio along height axis
    Camera(
        const Point& position, const Vect3& direction,
        size_t width, size_t height,
        Scalar gammaWidth, Scalar gammaHeight);

    /// \fn Ray getRay(unsigned int line, unsigned int column)
    /// \brief return Ray to enlight the pixel (line, column)
    /// \param line line of pixel
    /// \param column column of pixel
    /// \warning : direction must have the form (0, 0, z)
    /// \todo : fix getRay for other directions
    Ray getRay(unsigned int line, unsigned int column) const;

private:

    Point _position;
    Vect3 _direction;
    size_t _width;
    size_t _height;
    Scalar _gammaWidth;
    Scalar _gammaHeight;
};

#endif
