#ifndef RESOURCE_MANAGER_HPP
#define RESOURCE_MANAGER_HPP

#include <memory>
#include <unordered_map>
#include <string>
#include <iostream>
#include <typeinfo>

/// \class ResourceManager
/// \brief Manage the creation, deletion, access to all resource
/// \note Every resource created must be created with the instance of ResourceManager
template<class T>
class ResourceManager {
public:

    ResourceManager<T>(const ResourceManager<T>&) = delete;
    ResourceManager<T>(ResourceManager<T>&&) = delete;
    ResourceManager<T>& operator=(const ResourceManager<T>&) = delete;

    /// \fn getInstanceResourceManager<T>&
    /// \brief an implementation of pattern singleton : you have to call this function in order to use the ResourceManager
    static ResourceManager<T>& getInstance() {
        return _instance;
    }

    ~ResourceManager<T>() {
        std::cout << "Destructing ResourceManager of type : " << typeid(T).name() << std::endl;
    }

    /// \fn createResource
    /// \brief declare and create a resource
    /// \arg name the name associated to your resource
    /// \arg shape the newly created resource
    /// \example IShape* s = ResourceManager<IShape>::getInstance().createResource("foo", new Sphere(Vect3(0., 0., 0.), 1.));
    T* createResource(const std::string& name, T* resource){
        _resources.erase(name);
        _resources[name] = resource;
        return _resources[name].get();
    }

private:
    ResourceManager<T>() {
        std::cout << "Creating ResourceManager of type : " << typeid(T).name() << std::endl;
    }

    static ResourceManager<T> _instance;

    std::unordered_map<std::string, std::unique_ptr<T>> _resources;
};

template<class T>
ResourceManager<T> ResourceManager<T>::_instance;
#endif
