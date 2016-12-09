#ifndef SCENE_HPP
#define SCENE_HPP

#include <memory>
#include <vector>

#include "IShape.hpp"
#include "Ray.hpp"

class Scene {

public:

  Scene() = default;
  Scene(const Scene&) = delete;
  Scene& operator=(const Scene&) = delete;

  bool intersect(const Ray&, Point&) const;

private:

  std::vector<std::unique_ptr<IShape>> _shapes;
};

#endif
