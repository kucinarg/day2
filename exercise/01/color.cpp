#include "stdafx.h"
#include "color.h"
#include <algorithm>
#include <type_traits>



color::color(double const & red, double const & green, double const & blue) noexcept :
  red(std::clamp(red, 0., 1.)),
  green(std::clamp(green, 0., 1.)),
  blue(std::clamp(blue, 0., 1.))
{
}

double color::get_red() const noexcept
{
  return red;
}

double color::get_green() const noexcept
{
  return green;
}

double color::get_blue() const noexcept
{
  return blue;
}

double color::get_luminance() const noexcept
{
  return 0.2126 * red + 0.7152 * green + 0.0722 * blue;
}

COLORREF color::get_color_ref() const noexcept
{
  return RGB(char(red * 255), char(green * 255), char(blue * 255));
}

void color::set_red(double const & red) noexcept
{
  this->red = std::clamp(red, 0., 1.);
}

void color::set_green(double const & green) noexcept
{
  this->green = std::clamp(green, 0., 1.);
}

void color::set_blue(double const & blue) noexcept
{
  this->blue = std::clamp(blue, 0., 1.);
}

bool color::operator==(color const & other) const noexcept
{
  return red == other.red && blue == other.blue && green == other.green;
}

color const & color::operator=(color const & other) noexcept
{
  this->blue = other.blue;
  this->red = other.red;
  this->green = other.green;
  return *this;
}
