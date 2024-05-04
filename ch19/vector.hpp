#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "allocator.hpp"

#include <algorithm>
#include <initializer_list>
#include <iterator>
#include <stdexcept>
#include <ostream>
#include <memory>

template<typename T, typename Alloc> class vector;
template <typename T, typename Alloc>
std::ostream& operator<<(std::ostream &os, const vector<T,Alloc> &v);

template <typename T, typename Alloc = allocator<T>>
class vector {
public:
    using size_type = std::size_t;

public:
    friend std::ostream& operator<<<T,Alloc>(std::ostream &os, const vector &v);

public:
    vector() = default;
    explicit vector(size_type sz);
    vector(std::initializer_list<T> lst);
    ~vector();

    // copy semantics
    vector(const vector &rhs);
    vector& operator=(const vector &rhs);

    // move semantics
    vector(vector &&rhs) noexcept;
    vector& operator=(vector &&rhs) noexcept;

    void push_back(const T &d);

    void reserve(size_type new_alloc);
    void resize(size_type new_size, T val = T{});
    
    T& operator[](size_type n);
    const T& operator[](size_type n) const;

    T& at(size_type n);
    const T& at(size_type n) const;

    size_type size() const noexcept;
    size_type capacity() const noexcept;

    T* begin() noexcept { return m_elem; }
    T* end() noexcept { return m_elem + m_sz; }
    const T* cbegin() const noexcept { return m_elem; }
    const T* cend() const noexcept { return m_elem + m_sz; }

private:
    void free();


private:
    Alloc m_alloc;

private:
    size_type m_sz{};
    T *m_elem{};
    size_type m_space{};
};

template <typename T, typename Alloc>
vector<T,Alloc>::vector(size_type sz)
    : m_sz{sz},
      m_elem{m_alloc.allocate(sz)},
      m_space{sz}
{
    //if(0 > sz) throw std::invalid_argument{"vector::vector: negative size passed"};
}

template <typename T, typename Alloc>
vector<T,Alloc>::vector(std::initializer_list<T> lst)
    : m_sz{lst.size()},
      m_elem{m_alloc.allocate(lst.size())},
      m_space{m_sz}
{
    std::uninitialized_copy(lst.begin(), lst.end(), m_elem);
    // std::copy(lst.begin(), lst.end(), m_elem);
}

template <typename T, typename Alloc>
void vector<T,Alloc>::free() 
{
    if(!m_elem) return;

    for(auto q = m_elem; q != m_elem+m_sz; ++q) {
        m_alloc.destroy(q);
    }
    m_alloc.deallocate(m_elem, capacity());
}

template <typename T, typename Alloc>
vector<T,Alloc>::~vector()
{
    free();
}

template <typename T, typename Alloc>
vector<T,Alloc>::vector(const vector &rhs)
  : m_sz{rhs.m_sz},
    m_elem{m_alloc.allocate(rhs.m_sz)},
    m_space{m_sz}
{
    std::uninitialized_copy(rhs.m_elem, rhs.m_elem+rhs.m_sz, m_elem);
    // std::copy(rhs.m_elem, rhs.m_elem+rhs.m_space, m_elem);
}

template <typename T, typename Alloc>
vector<T,Alloc>& vector<T,Alloc>::operator=(const vector &rhs)
{
  if(this == &rhs) return *this;

  auto *tmp = m_alloc.allocate(rhs.m_sz);
  std::uninitialized_copy(rhs.m_elem, rhs.m_elem+rhs.m_sz, tmp);
  free();
  m_elem = tmp;
  m_sz = m_space = rhs.m_sz;
  return *this;
}

template <typename T, typename Alloc>
vector<T,Alloc>::vector(vector &&rhs) noexcept
  : m_sz{rhs.m_sz},
    m_elem{rhs.m_elem},
    m_space{m_sz}
{
  rhs.m_elem = nullptr;
  rhs.m_sz = rhs.m_space = 0;
}

template <typename T, typename Alloc>
vector<T,Alloc>& vector<T,Alloc>::operator=(vector &&rhs) noexcept
{
  if(this == &rhs) {
      return *this;
  }

  free();
  m_elem = rhs.m_elem;
  m_sz = m_space = rhs.m_sz;

  rhs.m_elem = nullptr;
  rhs.m_sz = rhs.m_space = 0;
  return *this;
}

template <typename T, typename Alloc>
void vector<T,Alloc>::push_back(const T &d)
{
    if(!capacity()) {
        reserve(8);
    }
    else if(size() == capacity()) {
        reserve(2*capacity());
    }
    m_alloc.construct(&m_elem[m_sz], d);
    ++m_sz;
}
 
template <typename T, typename Alloc>
void vector<T,Alloc>::reserve(size_type new_alloc)
{
    if(new_alloc <= m_space) return;

    std::unique_ptr<T> up{m_alloc.allocate(new_alloc)};
    std::uninitialized_copy(std::make_move_iterator(begin()),
                            std::make_move_iterator(end()), up.get());
    free();
    m_elem = up.release();
    m_space = new_alloc;
}

template <typename T, typename Alloc>
void vector<T,Alloc>::resize(size_type new_size, T val)
{
    if(new_size == 0) return;

    reserve(new_size);
    for(size_type i{m_sz}; i != new_size; ++i) {
        m_alloc.construct(&m_elem[i], val);
    }

    for(size_type i{new_size}; i < m_sz; ++i) {
        m_alloc.destroy(&m_elem[i]);
    }
    m_sz = new_size;
}

template <typename T, typename Alloc>
inline T& vector<T,Alloc>::operator[](size_type n)
{
  return m_elem[n];
}

template <typename T, typename Alloc>
inline const T& vector<T,Alloc>::operator[](size_type n) const
{
  return m_elem[n];
}

template <typename T, typename Alloc>
T& vector<T,Alloc>::at(size_type n)
{
    if(size() <= n) throw std::out_of_range{"vector<T,Alloc>::at: out of range"};
    return m_elem[n];
}

template <typename T, typename Alloc>
const T& vector<T,Alloc>::at(size_type n) const
{
    if(size() <= n) throw std::out_of_range{"vector<T,Alloc>::at: out of range"};
    return m_elem[n];
}

template <typename T, typename Alloc>
inline typename vector<T,Alloc>::size_type vector<T,Alloc>::size() const noexcept
{
  return m_sz;
}

template <typename T, typename Alloc>
inline typename vector<T,Alloc>::size_type vector<T,Alloc>::capacity() const noexcept
{
    return m_space;
}

template <typename T, typename Alloc>
std::ostream& operator<<(std::ostream &os, const vector<T,Alloc> &v)
{
    std::for_each(v.cbegin(), v.cend(),[&os](const auto &elem) {
            os << elem << ' ';
    });

    return os;
}

#endif
