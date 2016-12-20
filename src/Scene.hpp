#ifndef SCENE_HPP
#define SCENE_HPP

#include "Collection.hpp"

class Scene {

public:

    Scene() = default;
    Scene(const Scene&) = delete;
    Scene& operator=(const Scene&) = delete;

    void addShape(IShape*);
    OpCollision findCollision(const Ray&) const;

private:

    Collection _data;
};

#endif
