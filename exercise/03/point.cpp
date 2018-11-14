#include "point.h"

point::point(int x, int y) noexcept :
  x(x), y(y)
{
}

bool point::operator!=(point const & right) const noexcept
{
  return !(*this == right);
}

bool point::operator==(point const & right) const noexcept
{
  return right.x == x && right.y == y;
}

bool point::operator<(point const & right) const noexcept
{
  return x != right.x ? x < right.x : y < right.y;
}
