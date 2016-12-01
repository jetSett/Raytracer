#ifndef ISHAPE_HPP
#define ISHAPE_HPP

class IShape {
    
public:
    
    IShape() = default;
    
    Point intersect(const Ray&);
};

#endif
