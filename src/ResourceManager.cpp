
#include "ShapeManager.hpp"

// DEPRECATED

ShapeManager ShapeManager::_instance = ShapeManager();

ShapeManager& ShapeManager::getInstance(){
    return _instance;
}

ShapeManager::ShapeManager(){
    std::cout << "Creating ShapeManager" << std::endl;
}

ShapeManager::~ShapeManager(){
    std::cout << "Destructing ShapeManager" << std::endl;
    for(auto a : _shapeList){
        delete a.second;
    }
}

IShape* ShapeManager::createShape(const std::string& name, IShape* shape){
    if(_shapeList.find(name) != _shapeList.end()){
        delete _shapeList[name];
    }
    _shapeList[name] = shape;
    return _shapeList[name];
}
