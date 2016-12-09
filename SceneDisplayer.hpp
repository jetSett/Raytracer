#ifndef SCENE_DISPLAYER_HPP
#define SCENE_DISPLAYER_HPP

#include <vector>
#include <SFML/Graphics.hpp>

/// \class SceneDisplayer
/// \brief
class SceneDisplayer : public sf::Drawable, public sf::Transformable {

public:

  SceneDisplayer(unsigned int, unsigned int);
  void update(const std::vector<uint32_t>&);
  bool saveToFile(const std::string&) const;

private:

  virtual void draw(sf::RenderTarget&, sf::RenderStates) const override;

  unsigned int _width;
  unsigned int _height;
  sf::Image _image;
  sf::Texture _texture;
  sf::Sprite _sprite;
};

#endif
