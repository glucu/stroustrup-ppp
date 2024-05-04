#ifndef ALLOCATOR_HPP
#define ALLOCATOR_HPP

#include <cstdlib>
#include <memory>

template <typename T>
class allocator {
public:
    using size_type = std::size_t;
    using pointer = T*;
    using const_reference = const T&;

public:
    pointer allocate(size_type n);
    void deallocate(pointer p, size_type n);

    void construct(pointer p, const_reference value);
    void destroy(pointer p);

private:
    std::allocator<T> m_alloc;
};

template <typename T>
inline typename allocator<T>::pointer allocator<T>::allocate(size_type n)
{
    return m_alloc.allocate(n);
}

template <typename T>
inline void allocator<T>::deallocate(pointer p, size_type n)
{
    return m_alloc.deallocate(p,n);
}

template <typename T>
inline void allocator<T>::construct(pointer p, const_reference value)
{
    std::allocator_traits<decltype(m_alloc)>::construct(m_alloc, p, value);
}

template <typename T>
inline void allocator<T>::destroy(pointer p)
{
    std::allocator_traits<decltype(m_alloc)>::destroy(m_alloc, p);
}

#endif
