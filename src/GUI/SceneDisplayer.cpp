#include "SceneDisplayer.hpp"

SceneDisplayer::SceneDisplayer(size_t width, size_t height):
    _width(width), _height(height), _image(), _texture(), _sprite() {}

size_t SceneDisplayer::width() const {
    return _width;
}

size_t SceneDisplayer::height() const {
    return _height;
}

void SceneDisplayer::update(const std::vector<uint32_t>& pixels) {
    _image.create(_width, _height, reinterpret_cast<const sf::Uint8*>(pixels.data()));
    _texture.loadFromImage(_image);
    _sprite.setTexture(_texture);
}

void SceneDisplayer::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(_sprite, states);
}

bool SceneDisplayer::saveToFile(const std::string& filename) const {
    return _image.saveToFile(filename);
}
