#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "IShape.hpp"

/// \class Triangle
/// \brief represent a triangle
class Triangle : public IShape{
public:
    /// \fn Triangle
    /// \arg the vertices of our triangle
    Triangle(Point v1, Point v2, Point v3);

    virtual Scalar intersect(const Ray&) const override;
private:
    Point _v1, _v2, _v3;
};

#endif
