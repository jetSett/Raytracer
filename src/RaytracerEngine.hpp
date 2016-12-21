#ifndef RAYTRACER_ENGINE_HPP
#define RAYTRACER_ENGINE_HPP

#include "Scene.hpp"
#include "SceneDisplayer.hpp"
#include "Camera.hpp"
#include "Color.hpp"

class RaytracerEngine {
public:
    RaytracerEngine() = delete;
    RaytracerEngine(const RaytracerEngine&) = delete;
    RaytracerEngine& operator=(const RaytracerEngine&) = delete;
    RaytracerEngine(const Scene&, SceneDisplayer&);
    void updateScreen(Color, const Camera&);
private:
    Color getPixelColor(unsigned int, unsigned int, Color, const Camera&) const;
    const Scene& _scene;
    SceneDisplayer& _sceneDisplayer;
};

#endif
