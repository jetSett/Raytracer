#include <cstdlib>

#include <SFML/Graphics.hpp>

#include "SceneDisplayer.hpp"

int main(int, char * []) {

    const unsigned int width = 512;
    const unsigned int height = 256;

    SceneDisplayer displayer(width, height);
    sf::RenderWindow window(sf::VideoMode(width, height), "Raytracer 1.0");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(displayer);
        window.display();
    }

    return EXIT_SUCCESS;
}
