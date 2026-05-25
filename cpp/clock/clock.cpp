#include "clock.h"

namespace date_independent {

clock clock::at(int hour, int minute) { return clock(hour * 60 + minute); }

clock::clock(int minutes) {
  minutes %= 24 * 60;
  this->minutes = minutes < 0 ? minutes + 24 * 60 : minutes;
}

clock clock::plus(int minutes) { return clock(this->minutes + minutes); }

clock::operator std::string() const {
  std::string result;

  int hour = minutes / 60;
  if (hour < 10) {
    result += "0";
  }
  result += std::to_string(hour) + ":";

  int minute = minutes % 60;
  if (minute < 10) {
    result += "0";
  }
  result += std::to_string(minute);

  return result;
}

bool clock::operator==(const clock other) const {
  return other.minutes == this->minutes;
}

bool clock::operator!=(const clock other) const {
  return other.minutes != this->minutes;
}

} // namespace date_independent
