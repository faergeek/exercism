#pragma once

#include <string>

namespace date_independent {

class clock {
private:
  int hour;
  int minute;

public:
  static clock at(int hour, int minute);

  clock(int hour, int minute);
  clock plus(int minutes);

  operator std::string() const;
  bool operator==(const clock other) const;
  bool operator!=(const clock other) const;
};

} // namespace date_independent
