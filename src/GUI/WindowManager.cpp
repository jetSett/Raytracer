#include "WindowManager.hpp"

#include <Tools/ResourceManager.hpp>

Layout::Layout(unsigned int _nbLines, unsigned int _nbColumns):
    nbLines(_nbLines), nbColumns(_nbColumns) {}

size_t Layout::nbSections() const {
    return nbLines * nbColumns;
}

WindowManager::WindowManager(Layout layout, size_t displayerWidth, size_t displayerHeight):
    _layout(layout), _displayerWidth(displayerWidth), _displayerHeight(displayerHeight) {
    auto& displayers = ResourceManager<SceneDisplayer>::getInstance();
    for (unsigned int line = 0; line < _layout.nbLines; ++line) {
        for (unsigned int column = 0; column < _layout.nbColumns; ++column) {
            SceneDisplayer* displayer = displayers.createResource(new SceneDisplayer(_displayerWidth, _displayerHeight));
            displayer->setPosition(column*_displayerWidth, line*_displayerHeight);
            _displayers.emplace_back(displayer);
        }
    }
}

SceneDisplayer& WindowManager::operator()(unsigned line, unsigned column) const {
    return *_displayers[line*_layout.nbColumns + column];
}

const SceneDisplayer& WindowManager::operator()(unsigned line, unsigned column) const {
    return *_displayers[line*_layout.nbColumns + column];
}

void WindowManager::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    for (const auto& displayer : _displayers)
        target.draw(*displayer, states);
}
