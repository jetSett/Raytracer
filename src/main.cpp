#include <cstdlib>

#include <SFML/Graphics.hpp>

#include "SceneDisplayer.hpp"
#include "RaytracerEngine.hpp"
#include "ShapeManager.hpp"
#include "Sphere.hpp"
#include "Plane.hpp"

int main(int, char * []) {
    const unsigned int width = 1024;
    const unsigned int height = 512;

    // RaytracerEngine

    ShapeManager& shapeManager = ShapeManager::getInstance();
    Collection collection;
    collection.addShape(shapeManager.createShape("Big ball", new Sphere(absolut_origin+Vect3(0, 0, 500), 250)));

    SceneDisplayer displayer(width, height);
    RaytracerEngine engine(collection, displayer);

    Camera camera(absolut_origin, Vect3(0., 0., 1.), width, height, 1., 1.);
    engine.updateScreen(0xFFFFFFFF, camera);
    // Render Loop

    sf::RenderWindow window(sf::VideoMode(width, height), "Raytracer 1.0");

    while (window.isOpen()) {
        sf::Event event;
        if(window.waitEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(displayer);
        window.display();
    }

    return EXIT_SUCCESS;
}
