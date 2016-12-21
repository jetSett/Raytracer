#ifndef SCENE_HPP
#define SCENE_HPP

#include "Object.hpp"

class Scene {

public:

    Scene() = default;
    Scene(const Scene&) = delete;
    Scene& operator=(const Scene&) = delete;

    void addObject(Object*);
    OpCollision findCollision(const Ray&) const;

private:

    std::vector<Object*> _data;
};

#endif
