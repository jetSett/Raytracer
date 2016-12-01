#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "IShape.hpp"

class Sphere : public IShape {
    
public:

    virtual Point intersect(const Ray&) const override;
    
private:
    
};

#endif
