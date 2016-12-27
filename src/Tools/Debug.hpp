#ifndef DEBUG_HPP
#define DEBUG_HPP

#include <iostream>
#include <Core/Primitives.hpp>

#define D(c) std::cout << c << std::endl;
#define Dn(c) std::cout << #c << " : " << c << std::endl;

std::ostream& operator<<(std::ostream& stream, const Point& p);

#endif
