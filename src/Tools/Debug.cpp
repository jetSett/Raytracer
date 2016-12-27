#include "Debug.hpp"

std::ostream& operator<<(std::ostream& stream, const Point& p){
    stream << p.x << " " << p.y << " " << p.z;
    return stream;
}
