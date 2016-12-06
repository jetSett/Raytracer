#include "SceneDisplayer.hpp"

SceneDisplayer::SceneDisplayer(unsigned int width, unsigned int height):
  _width(width), _height(height), _image(), _texture(), _sprite() {

  }

void SceneDisplayer::update(const vector<uint32_t>& pixels) {
  _image.create(_with, _height, reinterpret_cast<const sf::Uint8*>(pixels.data()));
  _texture.loadFromImage(_image);
  _sprite.setTexture(_image);
}
