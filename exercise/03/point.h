#pragma once

struct point
{
  explicit point(int x = 0, int y = 0) noexcept;
  bool operator==(point const &) const noexcept;
  bool operator!=(point const &) const noexcept;
  bool operator<(point const &) const noexcept;
private:
  int x{ 0 }, y{0};

};