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

sf::VideoMode WindowManager::fitIn(unsigned int maxWidth, unsigned int maxHeight) {
    unsigned int actualWidth = _layout.nbColumns * _displayerWidth;
    unsigned int actualHeight = _layout.nbLines * _displayerHeight;
    double widthRatio = double(maxWidth) / double(actualWidth);
    double heightRatio = double(maxHeight) / double(actualHeight);
    double extremRatio = std::min(widthRatio, heightRatio);
    _displayerHeight *= extremRatio;
    _displayerWidth *= extremRatio;
    for (unsigned int line = 0; line < _layout.nbLines; ++line) {
        for (unsigned int column = 0; column < _layout.nbColumns; ++column) {
            SceneDisplayer& displayer = this->operator()(line, column);
            displayer.setScale(extremRatio, extremRatio);
            displayer.setPosition(column*_displayerWidth, line*_displayerHeight);
        }
    }
    return sf::VideoMode(
        _layout.nbColumns * _displayerWidth,
        _layout.nbLines * _displayerHeight);
}

void WindowManager::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    for (const auto& displayer : _displayers)
        target.draw(*displayer, states);
}
