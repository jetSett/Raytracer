#include "Object.hpp"

#include <iostream>

Object::Object(IShape* shape, Material* material):
    _shape(shape), _material(material){}

OpCollision Object::findCollision(const Ray& ray) const {
    OpScalar t = _shape->intersect(ray);
    t.ifelseOpReturn<OpCollision>([&](Scalar t){
        return OpCollision(Collision(t, this));
    },[](){
        return OpCollision();
    });
}

const IShape& Object::getShape() const {
    return *_shape;
}

const Material& Object::getMaterial() const {
    return *_material;
}

bool operator==(const Object& left, const Object& right) {
    return left._shape == right._shape
        && left._material == right._material;
}

bool operator!=(const Object& left, const Object& right) {
    return !(left == right);
}
