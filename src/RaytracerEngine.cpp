#include "RaytracerEngine.hpp"

#include <iostream>
#include <vector>

RaytracerEngine::RaytracerEngine(const Scene& scene, SceneDisplayer& sceneDisplayer):
    _scene(scene), _sceneDisplayer(sceneDisplayer) {}

void RaytracerEngine::updateScreen(Color backgroundColor, const Camera& camera) {
    std::vector<uint32_t> screen(_sceneDisplayer.width()*_sceneDisplayer.height(), backgroundColor.code());
    for (unsigned int line = 0; line < _sceneDisplayer.height(); ++line) {
        for (unsigned int column = 0; column < _sceneDisplayer.width(); ++column) {
            screen[line*_sceneDisplayer.width() + column] =
                getPixelColor(line, column, backgroundColor, camera).code();
        }
    }
    _sceneDisplayer.update(screen);
}

Color RaytracerEngine::getPixelColor(
    unsigned int line, unsigned int column,
    Color backgroundColor, const Camera& camera) const {

    Ray ray = camera.getRay(line, column);
    OpCollision collision = _scene.findCollision(ray);

    return collision.ifelseOpReturn<Color>(
    [&](const Collision& collision){
        // TODO add collision manager here
        Scalar t = collision.t / Scalar(Camera::farfarAway);
        Color color = collision.target->getMaterial().color;
        return modulate(color, (1-t)*(1-t));
    },
    [&](){
        return backgroundColor;
    });
}
