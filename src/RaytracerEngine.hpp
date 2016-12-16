#ifndef RAYTRACER_ENGINE_HPP
#define RAYTRACER_ENGINE_HPP

#include "Scene.hpp"
#include "SceneDisplayer.hpp"
#include "Camera.hpp"

class RaytracerEngine {

public:

    RaytracerEngine() = delete;
    RaytracerEngine(const RaytracerEngine&) = delete;
    RaytracerEngine& operator=(const RaytracerEngine&) = delete;
    RaytracerEngine(const Scene&, SceneDisplayer&);

    void updateScreen(uint32_t, const Camera&);

private:

    uint32_t updatePixel(unsigned int, unsigned int, uint32_t, const Camera&) const;

    const Scene& _scene;
    SceneDisplayer& _sceneDisplayer;
};

#endif
