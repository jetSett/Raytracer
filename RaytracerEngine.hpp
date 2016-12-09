#ifndef RAYTRACER_ENGINE_HPP
#define RAYTRACER_ENGINE_HPP

#include "Scene.hpp"
#include "SceneDisplayer.hpp"

class RaytracerEngine {

public:

  RaytracerEngine() = delete;
  RaytracerEngine(const RaytracerEngine&) = delete;
  RaytracerEngine& operator=(const RaytracerEngine&) = delete;
  RaytracerEngine(const Scene&, SceneDisplayer&);

  void updateScreen(uint32_t);

private:

  const Scene& _scene;
  SceneDisplayer& _sceneDisplayer;
};

#endif
