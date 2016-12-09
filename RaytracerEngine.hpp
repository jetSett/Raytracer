#ifndef RAYTRACER_ENGINE_HPP
#define RAYTRACER_ENGINE_HPP

#include <vector>

class RaytracerEngine {

public:

  RaytracerEngine(Scene&, SceneDisplayer&);

private:

  Scene& _scene;
  SceneDisplayer _sceneDisplayer;
  std::vector<uint32_t> _screen;
};

#endif
