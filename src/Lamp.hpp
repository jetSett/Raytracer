#ifndef LAMP_HPP
#define LAMP_HPP

#include <Core/Primitives.hpp>
#include <Scene.hpp>

class Lamp
{
public:
    Lamp(const Scene&);
    virtual OpVect3 point_of_view(Point) const = 0;
protected:
    const Scene& _scene;
};

class LampPoint : public Lamp{
public:
    LampPoint(const Scene&, Point);
    OpVect3 point_of_view(Point) const;
private:
    Point _position;
};

#endif
