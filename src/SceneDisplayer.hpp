#ifndef SCENE_DISPLAYER_HPP
#define SCENE_DISPLAYER_HPP

#include <vector>
#include <SFML/Graphics.hpp>

/// \class SceneDisplayer
/// \brief A class to display image, or save image on disk
class SceneDisplayer : public sf::Drawable, public sf::Transformable {

public:

  /// \fn SceneDisplayer(size_t width, size_t height)
  /// \brief Create new SceneDisplayer with of size width*height
  /// \param width and height
  SceneDisplayer(size_t, size_t);

  /// \fn width()
  /// \return width of screen
  size_t width() const;

  /// \fn height
  /// \return height of screen
  size_t height() const;

  /// \fn void update(const std::vector<uint32_t>& pixels)
  /// \brief update Image registered in SceneDisplayer
  /// WARNING : very slow, not designed for rendering loop
  /// \param name image a vector of colors, of size width * height
  void update(const std::vector<uint32_t>& image);

  /// \fn bool saveToFile(const std::string&)
  /// \brief save Image on disk
  /// \param name name of file, type of Image deduce from extension
  /// \return true if success, else false
  bool saveToFile(const std::string& name) const;

private:

    /// \fn void draw(sf::RenderTarget&, sf::RenderStates) const
    /// \brief surcharge of sf::Drawable::draw, required to print image with SFML
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const override;

    size_t _width;
    size_t _height;
    sf::Image _image;
    sf::Texture _texture;
    sf::Sprite _sprite;
};

#endif
