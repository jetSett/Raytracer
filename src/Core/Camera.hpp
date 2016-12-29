#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <Core/Primitives.hpp>
#include <Core/Ray.hpp>

/// \class Camera
/// \brief A class to manipulate cameras
class Camera {

public:

    /// \fn Camera(const Point&, const Vect3&, Scalar, Scalar)
    /// \brief construct a new Camera
    /// param position position of camera
    /// param direction longitude and latitude of camera
    /// param width width in pixels
    /// param height height in pixels
    /// param gammaWidth ratio along width axis
    /// param gammaHeight ratio along height axis
    Camera(
        const Point& position, const PolarCoordinates& direction,
        size_t width, size_t height,
        Scalar gammaWidth, Scalar gammaHeight);

    /// \fn Ray getRay(unsigned int line, unsigned int column)
    /// \brief return Ray to enlight the pixel (line, column)
    /// \param line line of pixel
    /// \param column column of pixel
    /// \warning : direction must have the form (longitude, 0)
    /// \todo : fix getRay for other directions
    Ray getRay(unsigned int line, unsigned int column) const;

    static const Scalar farfarAway;

private:

    Point _position;
    PolarCoordinates _direction;
    size_t _width;
    size_t _height;
    Scalar _gammaWidth;
    Scalar _gammaHeight;
};

#endif
