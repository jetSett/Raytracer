#ifndef RAYTRACER_ENGINE_HPP
#define RAYTRACER_ENGINE_HPP

class RaytracerEngine {

public:

  RaytracerEngine() = delete;
  RaytracerEngine(const RaytracerEngine&) = delete;
  RaytracerEngine& operator=(const RaytracerEngine&) = delete;
  RaytracerEngine(const Scene&, SceneDisplayer&);

  void updateScreen();

private:

  const Scene& _scene;
  SceneDisplayer& _sceneDisplayer;
};

#endif
