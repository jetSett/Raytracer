#include "Collection.hpp"

void Collection::addShape(IShape* shape) {
    _shapes.push_back(shape);
}

OpScalar Collection::intersect(const Ray& ray) const {
    OpScalar tMax;
    for (const auto& shape : _shapes) {
        shape->intersect(ray).ifOp( [&] (Scalar t){ //si il y a intersection, on effectue le morceau de code

            tMax.ifelseOp([&](Scalar& tM){
                if(tM > t){
                    tM = t;
                }
            }, [&](){
                tMax.assign(t);
            });

        });
    }
    return tMax;
}
