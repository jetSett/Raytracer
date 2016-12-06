#include "SceneDisplayer.hpp"

SceneDisplayer::SceneDisplayer(unsigned int width, unsigned int height):
  _width(width), _height(height), _image(), _texture(), _sprite() {

  }

void SceneDisplayer::update(const std::vector<uint32_t>& pixels) {
  _image.create(_width, _height, reinterpret_cast<const sf::Uint8*>(pixels.data()));
  _texture.loadFromImage(_image);
  _sprite.setTexture(_texture);
}

void SceneDisplayer::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  states.transform *= getTransform();
  states.texture = &_texture;
  target.draw(_sprite, states);
}
