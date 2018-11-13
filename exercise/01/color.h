#pragma once
#include <wtypes.h>

struct color
{
  color() noexcept = default;
  color(double const & red, double const & green, double const & blue) noexcept;
  color(color const &) noexcept = default;
  color(color&&) noexcept = default;
  double get_red() const noexcept;
  double get_green() const noexcept;
  double get_blue() const noexcept;
  double get_luminance() const noexcept;
  COLORREF get_color_ref() const noexcept;
  void set_red(double const & red) noexcept;
  void set_green(double const & green) noexcept;
  void set_blue(double const & blue) noexcept;
  bool operator==(color const&) const noexcept;
  color const & operator=(color const &) noexcept;
private:
  double red{0};
  double green{0};
  double blue{0};
};