#include "RaytracerEngine.hpp"

#include <iostream>
#include <vector>

RaytracerEngine::RaytracerEngine(const Scene& scene, SceneDisplayer& sceneDisplayer):
    _scene(scene), _sceneDisplayer(sceneDisplayer) {}

void RaytracerEngine::updateScreen(uint32_t backgroundColor, const Camera& camera) {
    const uint32_t alpha = (0xFF << (3 * 8));
    std::vector<uint32_t> screen(_sceneDisplayer.width()*_sceneDisplayer.height(), backgroundColor);
    for (unsigned int line = 0; line < _sceneDisplayer.height(); ++line) {
        for (unsigned int column = 0; column < _sceneDisplayer.width(); ++column) {
            screen[line*_sceneDisplayer.width() + column] =
                alpha | updatePixel(line, column, backgroundColor, camera);
        }
    }
    _sceneDisplayer.update(screen);
}

uint32_t RaytracerEngine::updatePixel(
    unsigned int line, unsigned int column,
    uint32_t backgroundColor, const Camera& camera) const {

    Ray ray = camera.getRay(line, column);
    Scalar t = _scene.findIntersection(ray);
    if (t == no_intersection)
        return backgroundColor;

    t /= Scalar(Camera::farfarAway);
    uint32_t color = 0xFF*(1-t)*(1-t);
    return color;
}
