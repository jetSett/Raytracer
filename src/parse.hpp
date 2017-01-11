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

PolarCoordinates polar_coordinates_from_tuple(PyObject * t);

const Color get_material(int k);

PyObject * parse(int argc, char * argv[]);
