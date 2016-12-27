#include <vector>
#include "RaytracerEngine.hpp"
#include <Tools/Chrono.hpp>

RaytracerEngine::RaytracerEngine(const Scene& scene, SceneDisplayer& sceneDisplayer, CollisionManager* col):
    _scene(scene), _sceneDisplayer(sceneDisplayer), _collisionMgr(col) {}

void RaytracerEngine::updateScreen(Color backgroundColor, const Camera& camera) {
    Chrono<> c;
    std::vector<uint32_t> screen(_sceneDisplayer.width()*_sceneDisplayer.height(), backgroundColor.code());
    #pragma omp for
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
        return _collisionMgr->getColor(collision);
    },
    [&](){
        return backgroundColor;
    });
}
