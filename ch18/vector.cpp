#include "vector.hpp"

#include <algorithm>
#include <stdexcept>

vector::vector(int sz)
    : m_sz{sz},
      m_elem{new double[sz]{}}
{
    if(0 > sz) throw std::invalid_argument{"vector::vector: negative size passed"};
}

vector::vector(std::initializer_list<double> lst)
    : m_sz{lst.size()},
      m_elem{new double[lst.size()]{}}
{
    std::copy(lst.begin(),  lst.end(), m_elem);
}

vector::~vector()
{
    delete[] m_elem;
}

vector::vector(const vector &rhs)
  : m_sz{rhs.m_sz},
    m_elem{new double[rhs.m_sz]}
{
  std::copy(rhs.m_elem, rhs.m_elem+rhs.m_sz, m_elem);
}

vector& vector::operator=(const vector &rhs)
{
  if(this == &rhs) return *this;

  auto *tmp = new double[rhs.m_sz];
  std::copy(rhs.m_elem, rhs.m_elem+rhs.m_sz, tmp);
  delete m_elem;
  m_elem = tmp;
  m_sz = rhs.m_sz;
  return *this;
}

vector::vector(vector &&rhs)
  : m_sz{rhs.m_sz},
    m_elem{rhs.m_elem}
{
  rhs.m_elem = nullptr;
  rhs.m_sz = 0;
}

vector& vector::operator=(vector &&rhs)
{
  if(this == &rhs) return *this;

  delete m_elem;
  m_elem = rhs.m_elem;
  m_sz = rhs.m_sz;

  rhs.m_elem = nullptr;
  rhs.m_sz = 0;
  return *this;
}

double& vector::operator[](int n)
{
  return m_elem[n];
}

const double& operator[](int n) const
{
  return m_elem[n];
}

int vector::size() const
{
  return m_sz;
}
