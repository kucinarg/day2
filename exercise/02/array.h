// do not use standard container as member or base class
#include <utility>
class array
{
  double* p{nullptr};
  int n{0};
public:
  array() noexcept = default;
  array(const int size, const double element);
  array(array const &);
  array(array&&) noexcept;
  ~array() noexcept;
  std::size_t size() const;
  double const & at(int i) const;
  array const & operator=(array const &);
  array& operator=(array && other);
};
