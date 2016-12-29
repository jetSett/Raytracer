#include "Camera.hpp"

#include <cmath>

const Scalar Camera::farfarAway = Scalar(1000);

Camera::Camera(const Point& position, const PolarCoordinates& direction, size_t width, size_t height, Scalar gammaWidth, Scalar gammaHeight):
    _position(position), _direction(direction),
    _width(width), _height(height), _gammaWidth(gammaWidth), _gammaHeight(gammaHeight)
{}

Ray Camera::getRay(unsigned int linePixel, unsigned int columnPixel) const {
    Scalar line = Scalar(linePixel) - Scalar(_height)/2;
    Scalar column = Scalar(columnPixel) - Scalar(_width)/2;
    const AngleRad phi = _direction.longitude;

    Point rayOrigin(_position);
    rayOrigin += Vect3(column*cos(phi), line, -column*sin(phi));

    Point rayTarget(_position);
    rayTarget += farfarAway*Vect3(sin(phi), 0, cos(phi));
    rayTarget += Vect3(column*_gammaWidth*cos(phi), line*_gammaHeight, -column*_gammaWidth*sin(phi));

    Vect3 dir = fromTo(rayOrigin, rayTarget);
    return Ray(rayOrigin, dir/dir.norm());
}
