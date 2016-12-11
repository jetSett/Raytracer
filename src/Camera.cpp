#include "Camera.hpp"

static Scalar farfarAway = Scalar(1000);

Camera::Camera(const Point& position, const Vect3& direction, Scalar gammaWidth, Scalar gammaHeight):
    _position(position), _direction(direction), _width(width), _height(height), _gammaWidth(gammaWidth), _gammaHeight(gammaHeight),
{}

Ray Camera::getRay(unsigned int linePixel, unsigned int columnPixel) const {
    Scalar line = Scalar(linePixel) - Scalar(height)/2;
    Scalar column = Scalar(columnPixel) - Scalar(width)/2;

    Point rayOrigin(_position);
    rayOrigin += Vect3(line, column, Scalar(0));

    Point rayTarget(_position);
    rayTarget += Vect3(line*gammaWidth, column*gammaHeight, farfarAway));

    return Ray(rayOrigin, fromTo(rayOrigin, rayDirection));
}
