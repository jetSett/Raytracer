#include "../Test.hpp"

#include <memory>
#include <functional>

void test1(){
    const unsigned int width = 1024;
    const unsigned int height = 512;

    auto& materials = ResourceManager<Material>::getInstance();
    auto& shapes = ResourceManager<IShape>::getInstance();
    auto& objects = ResourceManager<Object>::getInstance();

    Scene scene;
    auto addObject = [&](IShape* shape, Material* material){
        scene.addObject(objects.createResource(new Object(
            shapes.createResource(shape), materials.createResource(material))));
    };

    addObject(new Sphere(Point(0, 0, 500), 250), new Material(Color::Red));
    addObject(new Triangle(Point(0, 0, 1000), Point(300, -220, 500), Point(100, 200, 100)), new Material(Color::Green));
    addObject(new Sphere(Point(100, -50, 100), 50), new Material(Color::Yellow));
    addObject(new Sphere(Point(-200, 150, 400), 100), new Material(Color::Blue));
    addObject(new Triangle(Point(-500, -200, 100), Point(-300, -180, 100), Point(-400, 0, 100)), new Material(Color::Cyan));
    addObject(new Sphere(Point(100, -50, 100) + Vect3(-40, 75, 0), 50), new Material(Color::Magenta));

    SceneDisplayer displayer(width, height);
    RaytracerEngine engine(scene, displayer, new CollisionManager(new Light_Basic));

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
