#include "Camera.hpp"

static const Scalar farfarAway = Scalar(1000);

Camera::Camera(const Point& position, const Vect3& direction, size_t width, size_t height, Scalar gammaWidth, Scalar gammaHeight):
    _position(position), _direction(direction), _width(width), _height(height), _gammaWidth(gammaWidth), _gammaHeight(gammaHeight)
{}

Ray Camera::getRay(unsigned int linePixel, unsigned int columnPixel) const {
    Scalar line = Scalar(linePixel) - Scalar(_height)/2;
    Scalar column = Scalar(columnPixel) - Scalar(_width)/2;

    Point rayOrigin(_position);
    rayOrigin += Vect3(line, column, Scalar(0));

    Point rayTarget(_position);
    rayTarget += Vect3(line*_gammaWidth, column*_gammaHeight, farfarAway));

    return Ray(rayOrigin, fromTo(rayOrigin, rayTarget));
}
