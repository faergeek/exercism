#pragma once

#include <cstddef>

namespace space_age {

class space_age {
private:
  const size_t m_seconds;

public:
  space_age(const size_t seconds) : m_seconds(seconds) {}
  size_t seconds() const;
  double on_mercury() const;
  double on_venus() const;
  double on_earth() const;
  double on_mars() const;
  double on_jupiter() const;
  double on_saturn() const;
  double on_uranus() const;
  double on_neptune() const;
};

} // namespace space_age
