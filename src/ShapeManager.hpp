#ifndef SHAPEMANAGER_HPP
#define SHAPEMANAGER_HPP


#include <memory>
#include <unordered_map>
#include <string>
#include "IShape.hpp"


/// \class ShapeManager
/// \brief Manage the creation, deletion, access to all shape
/// \note Every shape created must be created with the instance of ShapeManager
class ShapeManager{
public:

    /// \fn getInstance
    /// \brief an implementation of pattern singleton : you have to call this function in order to use the ShapeManager
    static ShapeManager& getInstance();
    ~ShapeManager();


    /// \fn createShape
    /// \brief declare and create a shape
    /// \arg name the name associated to your shape
    /// \arg shape the newly created shape
    /// \example std::shared_ptr<IShape> s = ShapeManager::getInstance().createShape("foo", new Sphere(Vect3(0., 0., 0.), 1.));
    IShape* createShape(const std::string& name, IShape* shape);
private:
    ShapeManager();

    static ShapeManager _instance;

    std::unordered_map<std::string, IShape* > _shapeList;
};

#endif
