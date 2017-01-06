#include <iostream>
#include <boost/python.hpp>

#include <memory>
#include <functional>
#include <vector>

#include <Tools/Debug.hpp>

#include <GUI/WindowManager.hpp>
#include "RaytracerEngine.hpp"
#include <Shapes/Sphere.hpp>
#include <Shapes/Triangle.hpp>
#include "Scene.hpp"

#include <Tools/ResourceManager.hpp>

Point point_from_tuple(PyObject * t);

auto get_material(int k);

void launch(int argc, char * argv[]);
