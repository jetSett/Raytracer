#ifndef COLLISIONMANAGER_HPP
#define COLLISIONMANAGER_HPP

#include <memory>
#include <Tools/Functor.hpp>
#include <Tools/Color.hpp>
#include <Core/Collision.hpp>
#include <Core/Camera.hpp>
#include <Object.hpp>

using LightFunctor = Functor<Color, const Collision&>; // we will have to change that !

class Light_ZBuffer : public LightFunctor{
public:
    virtual Color operator()(const Collision& c);
};

class Light_Basic : public LightFunctor{
public:
    virtual Color operator()(const Collision& c);
};

class CollisionManager{
public:
    CollisionManager(LightFunctor* l);
    ~CollisionManager();
    Color getColor(const Collision& c) const;
private:
    std::unique_ptr<LightFunctor> _light;
};

#endif
