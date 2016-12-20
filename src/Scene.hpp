#ifndef SCENE_HPP
#define SCENE_HPP

class Scene {

public:

    Scene() = default;
    Scene(const Scene&) = delete;
    Scene& operator=(const Scene&) = delete;

    void addObject(const Object&);
    OpCollision findCollision(const Ray&) const;

private:

    std::vector<Object> _data;
};

#endif
