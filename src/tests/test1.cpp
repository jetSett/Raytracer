#include "../Test.hpp"

#include <memory>

void test1(){
    const unsigned int width = 1024;
    const unsigned int height = 512;

    // RaytracerEngine
    std::unique_ptr<IShape> a(new Sphere(Point(0, 0, 500), 250));
    std::unique_ptr<IShape> b(new Triangle(Point(0, 0, 1000), Point(300, -220, 500), Point(100, 200, 100)));
    std::unique_ptr<IShape> c(new Sphere(Point(100, -50, 100), 50));
    std::unique_ptr<IShape> d(new Sphere(Point(-200, 150, 400), 100));
    std::unique_ptr<IShape> e(new Triangle(Point(-500, -200, 100), Point(-300, -180, 100), Point(-400, 0, 100)));
    std::unique_ptr<IShape> f(new Sphere(Point(100, -50, 100) + Vect3(-40, 75, 0), 50));
    std::unique_ptr<Material> red(new Material(Color::Red));
    std::unique_ptr<Material> green(new Material(Color::Green));
    std::unique_ptr<Material> blue(new Material(Color::Blue));
    std::unique_ptr<Material> yellow(new Material(Color::Yellow));
    std::unique_ptr<Material> cyan(new Material(Color::Cyan));
    std::unique_ptr<Material> magenta(new Material(Color::Magenta));
    std::unique_ptr<Object> s(new Object(a.get(), red.get()));
    std::unique_ptr<Object> t(new Object(b.get(), green.get()));
    std::unique_ptr<Object> u(new Object(c.get(), yellow.get()));
    std::unique_ptr<Object> v(new Object(d.get(), blue.get()));
    std::unique_ptr<Object> w(new Object(e.get(), cyan.get()));
    std::unique_ptr<Object> x(new Object(f.get(), magenta.get()));

    Scene scene;
    scene.addObject(s.get());
    scene.addObject(t.get());
    scene.addObject(u.get());
    scene.addObject(v.get());
    scene.addObject(w.get());
    scene.addObject(x.get());

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
