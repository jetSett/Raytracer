#include "Object.hpp"

Object::Object(IShape* shape, IMaterial* material):
    _shape(shape), _material(material)

OpCollision Object::getCollision(const Ray& ray) const {
    OpScalar t = _shape->intersect(ray);
    t.ifelseOpReturn([&](Scalar t){
        return OpCollision(Collision(t, this));
    },[](){
        return OpCollision();
    });
}

const IMaterial& Object::getShape() const {
    return *_shape;
}

const IMaterial& getMaterial() const {
    return *_material;
}

bool operator==(const Object& left, const Object& right) {
    return left->_shape == right->_shape
        && left->_material == right->_material;
}

bool operator!=(const Object& left, const Object& right) {
    return !(left == right);
}
