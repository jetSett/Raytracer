#include <cstdlib>

#include <SFML/Graphics.hpp>

#include "SceneDisplayer.hpp"
#include "RaytracerEngine.hpp"
#include "ShapeManager.hpp"
#include "Sphere.hpp"

int main(int, char * []) {
    const unsigned int width = 512;
    const unsigned int height = 256;

    // RaytracerEngine

    ShapeManager& shapeManager = ShapeManager::getInstance();
    IShape* bigBall = shapeManager.createShape("Big ball", new Sphere(absolut_origin+Vect3(0, 0, 500), 250));
    Collection collection;
    collection.addShape(bigBall);

    SceneDisplayer displayer(width, height);
    RaytracerEngine engine(collection, displayer);

    Camera camera(absolut_origin, Vect3(0., 0., 1.), width, height, 1., 1.);
    engine.updateScreen(0xFFF0, camera);
    // Render Loop

    sf::RenderWindow window(sf::VideoMode(width, height), "Raytracer 1.0");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        window.draw(displayer);
        window.display();
    }

    return EXIT_SUCCESS;
}
