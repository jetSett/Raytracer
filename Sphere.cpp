#include "Sphere.hpp"

Sphere::Sphere(Point center, Scalar radius) : _center(center), _radius(radius){

}

bool Sphere::intersect(const Ray& ray, Point& out) const{
    // the equation to solve is : f(t) = (t**2)*(||d||)**2 -2*t*<d, OA> + ||OA||**2 - R**2 = 0
    Scalar scalarProduct = ray.direction.dot(fromTo(ray.origin, _center));
    Scalar squaredNormD = ray.direction.squaredNorm();
    Scalar reduced_discrim = (scalarProduct*scalarProduct - squaredNormD*(  fromTo(ray.origin, _center).squaredNorm() - _radius*_radius   ) );
    if(reduced_discrim < 0){
      return false;
    }else if(reduced_discrim == 0){
      Scalar t = scalarProduct/squaredNormD;
      out = ray.getPoint(t);
      return true;
    }else{
      Scalar t1 = (scalarProduct + sqrt(reduced_discrim))/squaredNormD, t2 = (scalarProduct - sqrt(reduced_discrim))/squaredNormD;
      if(t1 < 0 and t2 < 0){
        return false;
      }
      if(t1 < 0 and t2 >= 0){
        out = ray.getPoint(t2);
        return true;
      }
      if(t1 >= 0 and t2  < 0){
        out = ray.getPoint(t1);
        return true;
      }
      //here, we are sure that t1 >=0 and t2 >=0
      if(t1 > t2){
        out = ray.getPoint(t2);
      }else{
        out = ray.getPoint(t1);
      }
      return true;
    }
}
