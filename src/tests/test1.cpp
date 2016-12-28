#include "../Test.hpp"

#include <memory>
#include <functional>
#include <vector>

void test1(){
    const unsigned int width = 1024;
    const unsigned int height = 512;

    auto& materials = ResourceManager<Material>::getInstance();
    auto& shapes = ResourceManager<IShape>::getInstance();
    auto& objects = ResourceManager<Object>::getInstance();
    auto& lamps = ResourceManager<Lamp>::getInstance();

    Scene scene;
    LampSet lSet;

    auto addObject = [&](IShape* shape, Material* material){
        scene.addObject(objects.createResource(new Object(
            shapes.createResource(shape), materials.createResource(material))));
    };

    auto addLamp = [&](Lamp* l){
        lSet.push_back(lamps.createResource(l));
    };

    addObject(new Sphere(Point(0, 0, 500), 250), new Material(Color::Red));
    addObject(new Triangle(Point(0, 0, 1000), Point(300, -220, 500), Point(100, 200, 100)), new Material(Color::Green));
    addObject(new Sphere(Point(100, -50, 100), 50), new Material(Color::Yellow));
    addObject(new Sphere(Point(-200, 150, 400), 100), new Material(Color::Blue));
    addObject(new Triangle(Point(-500, -200, 100), Point(-300, -180, 100), Point(-400, 0, 100)), new Material(Color::Cyan));
    addObject(new Sphere(Point(100, -50, 100) + Vect3(-40, 75, 0), 50), new Material(Color::Magenta));

    addLamp(new LampPoint(scene, Point(0, 0, -200)));
    addLamp(new LampPoint(scene, Point(0, 500, 0)));
    addLamp(new LampPoint(scene, Point(100, 100, 0)));

    std::vector<CollisionManager*> collisionManagers = {
        new CollisionManager(new Light_ZBuffer),
        new CollisionManager(new Light_Basic),
        new CollisionManager(new Light_Multi(lSet))
    };

    float ratio = 1.f / float(collisionManagers.size());
    float windowWidth = ratio*width;
    float windowHeight = ratio*height;

    std::vector<std::unique_ptr<SceneDisplayer>> displayers;
    std::vector<std::unique_ptr<RaytracerEngine>> engines;
    for (unsigned int subwindow = 0; subwindow < collisionManagers.size(); ++subwindow) {
        displayers.emplace_back(new SceneDisplayer(width, height));
        displayers[subwindow]->setPosition(subwindow*windowWidth, 0.f);
        displayers[subwindow]->setScale(ratio, ratio);
        engines.emplace_back(new RaytracerEngine(scene, *displayers[subwindow], collisionManagers[subwindow]));
    }

    Camera camera(absolut_origin, Vect3(0., 0., 1.), width, height, 1., 1.);
    for (const auto& engine : engines)
        engine->updateScreen(Color::Black, camera);

    // Render Loop
    sf::RenderWindow window(sf::VideoMode(width, windowHeight), "RaytracerEngine");

    while (window.isOpen()) {

        window.clear();
        for (const auto& displayer : displayers)
            window.draw(*displayer);
        window.display();

        sf::Event event;
        if(window.isOpen()){
            if(window.waitEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
        }
    }
}
