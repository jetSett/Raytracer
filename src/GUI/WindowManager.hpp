#ifndef WINDOW_MANAGER_HPP
#define WINDOW_MANAGER_HPP

#include <SFML/Graphics.hpp>
#include <GUI/SceneDisplayer.hpp>

class Layout {
public:
    Layout() = default;
    Layout(unsigned int, unsigned int);
    size_t nbSections() const;
    unsigned int nbLines;
    unsigned int nbColumns;
};

class WindowManager : public sf::Drawable, public sf::Transformable {
public:
    WindowManager(Layout, size_t, size_t);
    SceneDisplayer& operator()(unsigned, unsigned) const;
    sf::VideoMode fitIn(unsigned int, unsigned int);
private:
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const override;
    const Layout _layout;
    unsigned int _displayerWidth;
    unsigned int _displayerHeight;
    std::vector<SceneDisplayer*> _displayers;
};

#endif
