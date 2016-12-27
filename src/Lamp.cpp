#include <Tools/Debug.hpp>
#include "Lamp.hpp"

Lamp::Lamp(const Scene& s) : _scene(s){
}

LampPoint::LampPoint(const Scene& s, Point p) : Lamp(s), _position(p){
}

OpVect3 LampPoint::point_of_view(Point M) const{
    Ray r(M, fromTo(M, _position));
    return _scene.findCollision(r).ifelseOpReturn<OpVect3>([&](Collision c){
        if(c.t <= 1.){
            return OpVect3();
        }else{
            return OpVect3(fromTo(_position, M).normalized());
        }
    }, [&](){
        return OpVect3(fromTo(_position, M).normalized());
    });
}
