#include "RaytracerEngine.hpp"

#include <vector>

RaytracerEngine::RaytracerEngine(const Scene& scene, SceneDisplayer& sceneDisplayer):
  _scene(scene), _sceneDisplayer(sceneDisplayer) {}

void RaytracerEngine::updateScreen(uint32_t backgroundColor) {
  vector<uint32_t> screen(_sceneDisplayer.width()*_sceneDisplayer.height(), backgroundColor);
  for (unsigned int line = 0; line < _sceneDisplayer.height(); ++line) {
    for (unsigned int column = 0; column < _sceneDisplayer.width(); ++column) {
      // TODO something
    }
  }
  _sceneDisplayer.update(screen);
}
