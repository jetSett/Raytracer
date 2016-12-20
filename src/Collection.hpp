#ifndef COLLECTION_HPP
#define COLLECTION_HPP

#include <memory>
#include <vector>

#include "IShape.hpp"
#include "Ray.hpp"

class Collection {

public:

  Collection() = default;

  void addShape(IShape*);
  OpCollision findCollision(const Ray&) const;

private:

  std::vector<IShape*> _shapes;
};

#endif
