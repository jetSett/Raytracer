#ifndef FUNCTOR_HPP
#define FUNCTOR_HPP

template<typename T, typename... Args>
class Functor{
public:
    virtual T operator()(Args... args) = 0;
};

#endif
