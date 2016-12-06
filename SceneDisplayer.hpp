#ifndef SCENE_DISPLAYER_HPP
#define SCENE_DISPLAYER_HPP

#include <SFML/Graphics.hpp>

class SceneDisplayer : public sf::Drawable, public sf::Transformable {

public:

  SceneDisplayer(unsigned int, unsigned int);
  void update(const std::vector<Color>&);
  virtual void draw(sf::RenderTarget&, sf::RenderStates) const override;

private:

  unsigned int _width;
  unsigned int _height;
};

#endif
