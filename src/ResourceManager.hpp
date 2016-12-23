#ifndef SHAPEMANAGER_HPP
#define SHAPEMANAGER_HPP

#include <memory>
#include <unordered_map>
#include <string>
#include <iostream>

#include "IShape.hpp"

// DEPRECATED

/// \class ShapeManager
/// \brief Manage the creation, deletion, access to all shape
/// \note Every shape created must be created with the instance of ShapeManager
class ShapeManager{
public:

    /// \fn getInstance
    /// \brief an implementation of pattern singleton : you have to call this function in order to use the ShapeManager
    static ShapeManager& getInstance() {
        return _instance;
    }

    ~ShapeManager() {
        std::cout << "Destructing ShapeManager" << std::endl;
        for(auto a : _shapeList) {
            delete a.second;
        }
    }


    /// \fn createShape
    /// \brief declare and create a shape
    /// \arg name the name associated to your shape
    /// \arg shape the newly created shape
    /// \example std::shared_ptr<IShape> s = ShapeManager::getInstance().createShape("foo", new Sphere(Vect3(0., 0., 0.), 1.));
    IShape* createShape(const std::string& name, IShape* shape){
        if(_shapeList.find(name) != _shapeList.end()){
            delete _shapeList[name];
        }
        _shapeList[name] = shape;
        return _shapeList[name];
    }

private:
    ShapeManager() {
        std::cout << "Creating ShapeManager" << std::endl;
    }

    static ShapeManager _instance = ShapeManager();

    std::unordered_map<std::string, IShape* > _shapeList;
};

#endif
