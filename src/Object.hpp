#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "IShape.hpp"
#include "IMaterial.hpp"
#include "Collision.hpp"
#include "Ray.hpp"

class Object {

public:

    Object(IShape*, IMaterial*);
    OpCollision getCollision(const Ray&) const;
    const IMaterial& getShape() const;
    const IMaterial& getMaterial() const;

    friend bool operator==(const Object&, const Object&);
    friend bool operator!=(const Object&, const Object&);

private:
    IShape* _shape;
    Material* _material;
};

#endif
