#ifndef COLLISION_MANAGER_HPP
#define COLLISION_MANAGER_HPP

#include <Tools/Color.hpp>
#include <Core/Collision.hpp>
#include <Core/Camera.hpp>
#include <Object.hpp>

class ICollisionManager {
public:
    ICollisionManager() = default;
    virtual Color operator()(const Collision& c) const = 0;
};

class Light_ZBuffer : public ICollisionManager {
public:
    virtual Color operator()(const Collision& c) const override;
};

class Light_Basic : public ICollisionManager {
public:
    virtual Color operator()(const Collision& c) const override;
};

namespace CollisionManager {
    extern Light_ZBuffer zbuffer;
    extern Light_Basic basic;
};

#endif
