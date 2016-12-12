#include "../Test.hpp"

void test1(){
    const unsigned int width = 1024;
    const unsigned int height = 512;

    // RaytracerEngine

    ShapeManager& shapeManager = ShapeManager::getInstance();
    Collection collection;
    // collection.addShape(shapeManager.createShape("Big ball", new Sphere(absolut_origin+Vect3(0, 0, 500), 250)));
    collection.addShape(shapeManager.createShape("Triangle", new Triangle(  Point(0, 0, 1000),
                                                                            Point(200, 0, 500),
                                                                            Point(200, 200, 200))));

    SceneDisplayer displayer(width, height);
    RaytracerEngine engine(collection, displayer);

    Camera camera(absolut_origin, Vect3(0., 0., 1.), width, height, 1., 1.);
<<<<<<< HEAD:src/tests/test1.cpp
    engine.updateScreen(0x00000000, camera);
=======
    engine.updateScreen(0xFFFFFFFF, camera);
>>>>>>> d2e85a92f8d84e8ff22231c65d8298ee8780fa6c:src/main.cpp
    // Render Loop

    sf::RenderWindow window(sf::VideoMode(width, height), "Raytracer 1.0");

    while (window.isOpen()) {

        window.clear();
        window.draw(displayer);
        window.display();

        sf::Event event;
        if(window.waitEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

    }

}
