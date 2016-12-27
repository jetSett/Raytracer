#ifndef LAMP_HPP
#define LAMP_HPP

#include <Core/Primitives.hpp>
#include <Scene.hpp>

class Lamp
{
public:
    Lamp(const Scene&);
    virtual bool is_seen(Point) const = 0;
protected:
    const Scene& _scene;
};

class LampPoint : public Lamp{
public:
    LampPoint(const Scene&, Point);
    bool is_seen(Point) const;
private:
    Point _position;
};

#endif
