#include "RaytracerEngine.hpp"

#include <iostream>
#include <vector>

RaytracerEngine::RaytracerEngine(const Scene& scene, SceneDisplayer& sceneDisplayer):
    _scene(scene), _sceneDisplayer(sceneDisplayer) {}

void RaytracerEngine::updateScreen(uint32_t backgroundColor, const Camera& camera) {
    const uint32_t alpha = (0xFF << (3 * 8));
    std::vector<uint32_t> screen(_sceneDisplayer.width()*_sceneDisplayer.height(), backgroundColor | alpha);
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
    OpCollision collision = _scene.findCollision(ray);

    return collision.ifelseOpReturn<uint32_t>(
    [&](const Collision& collision){
        // TODO add collision manager here
        Scalar t = collision.t / Scalar(Camera::farfarAway);
        uint32_t color = collision.target->getMaterial().color;
        return color*(1-t)*(1-t);
    },
    [&](){
        return backgroundColor;
    });
}
