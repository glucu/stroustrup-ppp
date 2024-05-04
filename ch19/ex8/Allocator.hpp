#ifndef ALLOCATOR_HPP
#define ALLOCATOR_HPP

#include <cstddef>
#include <cstdlib>
#include <limits>
#include <stdexcept>
#include <type_traits>

template <typename T>
class Allocator {
public:
    using size_type = std::size_t;
    using pointer = T*;

public:
    Allocator() = default;
    ~Allocator() = default;

    T* allocate(size_type n);
    void construct(pointer p, const T &value);
    void destroy(pointer p);
    void deallocate(pointer p, size_type);
};

template <typename T>
T* Allocator<T>::allocate(size_type n)
{
   if(std::numeric_limits<std::size_t>::max() / sizeof(T) < n) {
       throw std::runtime_error{"allocate: overflow of parameter n"};
   }
               
   return static_cast<T*>(malloc(n * sizeof(T)));
}

template <typename T>
void Allocator<T>::construct(pointer p, const T &value)
{
    new(p) T{value};
}

template <typename T>
void Allocator<T>::destroy(pointer p)
{
    if(!p) return;

    p->~T();
}

template <typename T>
void Allocator<T>::deallocate(pointer p, size_type)
{
    free(p);
}

#endif
