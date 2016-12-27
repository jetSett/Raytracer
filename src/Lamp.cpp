#include "Lamp.hpp"

Lamp::Lamp(const Scene& s) : _scene(s){
}

LampPoint::LampPoint(const Scene& s, Point p) : Lamp(s), _position(p){
}

bool LampPoint::is_seen(Point M) const{
    Ray r(M, fromTo(M, _position));
    return _scene.findCollision(r).ifelseOpReturn<bool>([](Collision c){
        if(c.t <= 1.){
            return false;
        }else{
            return true;
        }
    }, [](){
        return true;
    });
}
