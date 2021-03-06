#ifndef RAYTRACER_ENGINE_HPP
#define RAYTRACER_ENGINE_HPP

#include <memory>
#include "Scene.hpp"
#include <GUI/SceneDisplayer.hpp>
#include <Core/Camera.hpp>
#include <Tools/Color.hpp>
#include <CollisionManager.hpp>

class RaytracerEngine {
public:
    RaytracerEngine() = delete;
    RaytracerEngine(const RaytracerEngine&) = delete;
    RaytracerEngine& operator=(const RaytracerEngine&) = delete;
    RaytracerEngine(const Scene&, SceneDisplayer&, CollisionManager* col);
    void updateScreen(Color, const Camera&);
private:
    std::unique_ptr<CollisionManager> _collisionMgr;
    Color getPixelColor(unsigned int, unsigned int, Color, const Camera&) const;
    const Scene& _scene;
    SceneDisplayer& _sceneDisplayer;
};

#endif
