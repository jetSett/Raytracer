#ifndef COLLECTION_HPP
#define COLLECTION_HPP

#include <memory>
#include <vector>

#include "IShape.hpp"
#include "Ray.hpp"

class Collection {

public:

  Collection() = default;

  Scalar intersect(const Ray&) const;

private:

  std::vector<IShape*> _shapes;
};

#endif
