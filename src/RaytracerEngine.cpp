#include "RaytracerEngine.hpp"

#include <vector>

RaytracerEngine::RaytracerEngine(const Collection& scene, SceneDisplayer& sceneDisplayer):
    _collection(collection), _sceneDisplayer(sceneDisplayer) {}

void RaytracerEngine::updateScreen(uint32_t backgroundColor, const Camera& camera) {
    std::vector<uint32_t> screen(_sceneDisplayer.width()*_sceneDisplayer.height(), backgroundColor);
    for (unsigned int line = 0; line < _sceneDisplayer.height(); ++line) {
        for (unsigned int column = 0; column < _sceneDisplayer.width(); ++column) {
            Ray ray = camera.getRay(line, column);
            // Scalar t = ;
        }
    }
    _sceneDisplayer.update(screen);
}
