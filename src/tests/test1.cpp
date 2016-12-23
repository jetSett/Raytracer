#include "../Test.hpp"

#include <memory>

void test1(){
    const unsigned int width = 1024;
    const unsigned int height = 512;

    auto& materials = ResourceManager<Material>::getInstance();
    Material* red = materials.createResource(new Material(Color::Red));
    Material* green = materials.createResource(new Material(Color::Green));
    Material* blue = materials.createResource(new Material(Color::Blue));
    Material* yellow = materials.createResource(new Material(Color::Yellow));
    Material* cyan = materials.createResource(new Material(Color::Cyan));
    Material* magenta = materials.createResource(new Material(Color::Magenta));

    auto& shapes = ResourceManager<IShape>::getInstance();
    auto& objects = ResourceManager<Object>::getInstance();

    Scene scene;

    scene.addObject(objects.createResource(new Object(shapes.createResource(
        new Sphere(Point(0, 0, 500), 250)), red)));
    scene.addObject(objects.createResource(new Object(shapes.createResource(
        new Triangle(Point(0, 0, 1000), Point(300, -220, 500), Point(100, 200, 100))), green)));
    scene.addObject(objects.createResource(new Object(shapes.createResource(
        new Sphere(Point(100, -50, 100), 50)), yellow)));
    scene.addObject(objects.createResource(new Object(shapes.createResource(
        new Sphere(Point(-200, 150, 400), 100)), blue)));
    scene.addObject(objects.createResource(new Object(shapes.createResource(
        new Triangle(Point(-500, -200, 100), Point(-300, -180, 100), Point(-400, 0, 100))), cyan)));
    scene.addObject(objects.createResource(new Object(shapes.createResource(
        new Sphere(Point(100, -50, 100) + Vect3(-40, 75, 0), 50)), magenta)));

    SceneDisplayer displayer(width, height);
    RaytracerEngine engine(scene, displayer);

    Camera camera(absolut_origin, Vect3(0., 0., 1.), width, height, 1., 1.);
    engine.updateScreen(Color::Black, camera);

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
