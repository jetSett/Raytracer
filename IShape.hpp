#ifndef ISHAPE_HPP
#define ISHAPE_HPP

class IShape {
    
public:
    
    IShape() = default;
    
    virtual Point intersect(const Ray&) = 0;
};

#endif
