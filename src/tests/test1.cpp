#include "../Test.hpp"

#include <memory>
#include <functional>
#include <vector>

#include <Tools/Debug.hpp>

void test1(){
    const unsigned int width = 832;
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

    // addLamp(new LampPoint(scene, Point(0, 800, -2000)));
    addLamp(new LampPoint(scene, Point(0, 500, -200)));
    addLamp(new LampPoint(scene, Point(-400, 100, 0)));
    // addLamp(new LampPoint(scene, Point(0, 0, 500)));

    std::vector<CollisionManager*> collisionManagers = {
        //new CollisionManager(new Light_ZBuffer),
        // new CollisionManager(new Light_Basic),
        new CollisionManager(new Light_Multi(lSet)),
        new CollisionManager(new Light_Multi(lSet)),
        new CollisionManager(new Light_Multi(lSet)),
        new CollisionManager(new Light_Multi(lSet))
    };

    WindowManager displayers(Layout(2, 2), width, height);
    std::vector<std::pair<unsigned int, unsigned int>> pos = {
        std::make_pair(0u, 0u),
        std::make_pair(0u, 1u),
        std::make_pair(1u, 0u),
        std::make_pair(1u, 1u)
    };

    std::vector<Camera> cameras = {
        Camera(absolut_origin, PolarCoordinates(-0.30, 0.), width, height, 1., 1.),
        Camera(absolut_origin, PolarCoordinates(-0.15, 0.), width, height, 1., 1.),
        Camera(absolut_origin, PolarCoordinates( 0.15, 0.), width, height, 1., 1.),
        Camera(absolut_origin, PolarCoordinates( 0.30, 0.), width, height, 1., 1.)
    };

    std::vector<std::unique_ptr<RaytracerEngine>> engines;
    for (unsigned int i = 0; i < collisionManagers.size(); ++i) {
        engines.emplace_back(new RaytracerEngine(
            scene,
            displayers(pos[i].first, pos[i].second),
            collisionManagers[i]));
        engines[i]->updateScreen(Color::Black, cameras[i]);
    }

    // Render Loop
    sf::RenderWindow window(displayers.fitIn(1036,832), "RaytracerEngine");
    while (window.isOpen()) {

        window.clear();
        window.draw(displayers);
        window.display();

        sf::Event event;
        if(window.waitEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
}
