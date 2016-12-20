#include "../Test.hpp"

void test1(){
    const unsigned int width = 1024;
    const unsigned int height = 512;

    // RaytracerEngine

    Scene scene;
    scene.addShape(Object(new Sphere(absolut_origin+Vect3(0, 0, 500), 250)));
    scene.addShape(Object(new Triangle(  Point(0, 0, 1000), Point(200, 0, 500), Point(200, 200, 200))));
    scene.addShape(Object(new Sphere(absolut_origin+Vect3(100, -50, 100), 50)));
    scene.addShape(Object(new Sphere(absolut_origin+Vect3(-200, 150, 400), 100)));

    SceneDisplayer displayer(width, height);
    RaytracerEngine engine(scene, displayer);

    Camera camera(absolut_origin, Vect3(0., 0., 1.), width, height, 1., 1.);
    engine.updateScreen(0x00000000, camera);

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
