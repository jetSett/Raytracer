#ifndef RESOURCE_MANAGER_HPP
#define RESOURCE_MANAGER_HPP

#include <memory>
#include <unordered_map>
#include <string>
#include <iostream>

/// \class ShapeManager
/// \brief Manage the creation, deletion, access to all shape
/// \note Every shape created must be created with the instance of ShapeManager
template<class T>
class ResourceManager {
public:

    /// \fn getInstance
    /// \brief an implementation of pattern singleton : you have to call this function in order to use the ShapeManager
    static ResourceManager<T>& getInstance() {
        return _instance;
    }

    ~ResourceManager<T>() {
        std::cout << "Destructing ResourceManager" << std::endl;
        for(auto a : _resourceList) {
            delete a.second;
        }
    }

    /// \fn createShape
    /// \brief declare and create a shape
    /// \arg name the name associated to your shape
    /// \arg shape the newly created shape
    /// \example std::shared_ptr<IShape> s = ShapeManager::getInstance().createShape("foo", new Sphere(Vect3(0., 0., 0.), 1.));
    T* createShape(const std::string& name, T* shape){
        if(_resourceList.find(name) != _resourceList.end()){
            delete _resourceList[name];
        }
        _resourceList[name] = shape;
        return _resourceList[name];
    }

private:
    ResourceManager<T>() {
        std::cout << "Creating ResourceManager" << std::endl;
    }

    static ResourceManager<T> _instance();

    std::unordered_map<std::string, T* > _resourceList;
};

#endif
