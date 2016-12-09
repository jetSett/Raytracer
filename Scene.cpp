#include "Scene.hpp"

bool Scene::intersect(const Ray& ray, Point& out) const {
  bool found = false;
  Scalar tMax;
  for (const auto& shape : _shapes) {
    Point p;
    if (shape->intersect(ray, p)) {
      Vect3 v(fromTo(ray.origin, p));
      Scalar t = v.squaredNorm();
      if (!found || t < tMax) {
        tMax = t;
        out = p;
      }
      found = true;
    }
  }

  return found;
}
