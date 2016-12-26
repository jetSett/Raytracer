#ifndef RESOURCE_MANAGER_HPP
#define RESOURCE_MANAGER_HPP

#include <cstdlib>
#include <memory>
#include <unordered_map>
#include <string>
#include <iostream>
#include <sstream>
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
    /// \example IShape* s = ResourceManager<IShape>::getInstance().createResource(new Sphere(Vect3(0., 0., 0.), 1.), "foo");
    T* createResource(T* resource, std::string name = std::string("")) {
        name += "__number__";
        _counter += 1;
        std::ostringstream ss;
        ss << _counter;
        name += ss.str();

        _resources[name].reset(resource);
        return _resources[name].get();
    }

private:
    ResourceManager<T>() {
        std::cout << "Creating ResourceManager of type : " << typeid(T).name() << std::endl;
    }

    static ResourceManager<T> _instance;
    static unsigned int _counter;

    std::unordered_map<std::string, std::unique_ptr<T>> _resources;
};

template<class T>
ResourceManager<T> ResourceManager<T>::_instance;

template<class T>
unsigned int ResourceManager<T>::_counter(0);

#endif
