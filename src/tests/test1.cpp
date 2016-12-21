#include "../Test.hpp"

#include <memory>

void test1(){
    const unsigned int width = 1024;
    const unsigned int height = 512;

    // RaytracerEngine
    std::unique_ptr<IShape> a(new Sphere(absolut_origin+Vect3(0, 0, 500), 250));
    std::unique_ptr<IShape> b(new Triangle(Point(0, 0, 1000), Point(200, 0, 500), Point(200, 200, 200)));
    std::unique_ptr<IShape> c(new Sphere(absolut_origin+Vect3(100, -50, 100), 50));
    std::unique_ptr<IShape> d(new Sphere(absolut_origin+Vect3(-200, 150, 400), 100));
    std::unique_ptr<Material> m(new Material(0x00FFFFFF));
    std::unique_ptr<Object> s(new Object(a.get(), m.get()));
    std::unique_ptr<Object> t(new Object(b.get(), m.get()));
    std::unique_ptr<Object> u(new Object(c.get(), m.get()));
    std::unique_ptr<Object> v(new Object(d.get(), m.get()));

    Scene scene;
    scene.addObject(s.get());
    scene.addObject(t.get());
    scene.addObject(u.get());
    scene.addObject(v.get());

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
