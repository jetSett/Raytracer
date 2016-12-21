#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "IShape.hpp"
#include "Material.hpp"
#include "Collision.hpp"
#include "Ray.hpp"

class Object {

public:

    Object(IShape*, Material*);
    OpCollision findCollision(const Ray&) const;
    const IShape& getShape() const;
    const Material& getMaterial() const;

    friend bool operator==(const Object&, const Object&);
    friend bool operator!=(const Object&, const Object&);

private:
    IShape* _shape;
    Material* _material;
};

#endif
