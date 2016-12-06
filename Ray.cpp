#include "Ray.hpp"

Ray::Ray(const Point& o, const Vect3& dir) : origin(o), direction(dir){
}

Point Ray::getPoint(Scalar t) const{
  return origin + (t*direction);
}
