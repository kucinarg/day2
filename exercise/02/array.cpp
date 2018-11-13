#include "array.h"
#include <algorithm>
#include <stdexcept>
#include <vector>

array::array(const int size, const double element)
{
  if (size < 0)
    return;
  p = new double[size];
  n = size;
  std::generate_n(p, n, [&element]() {return element; });
}

array::array(array const & other)
{
  if (!other.size())
    return;
  p = new double[other.size()];
  n = other.size();
  std::copy(other.p, other.p + other.size(), p);
}

array::array(array && other) noexcept :
  p(other.p),
  n(other.n)
{
  other.p = nullptr;
  other.n = 0;
}

std::size_t array::size() const noexcept
{
  return std::size_t(n);
}

array::~array() noexcept
{
  if (!p)
    return;

  delete[] p;
}

double const & array::at(int i) const
{
  if (i < 0 || i > n || size() == 0)
    throw std::out_of_range("index out of range");
  return p[i];
}

array const & array::operator=(array const & other)
{
  if (std::addressof(other) == this)
    return *this;
  array tmp = other;
  *this = std::move(tmp);
  return *this;
}

array & array::operator=(array && other) noexcept
{
  if (std::addressof(other) == this)
    return *this;

  if (p)
    delete p;
  p = other.p;
  n = other.n;
  other.p = nullptr;
  other.n = 0;
  return *this;
}

  