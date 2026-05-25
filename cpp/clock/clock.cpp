#include "clock.h"

namespace date_independent {

clock clock::at(int hour, int minute) { return clock(hour, minute); }

clock::clock(int hour, int minute) {
  hour += minute / 60;
  minute %= 60;
  if (minute < 0) {
    hour -= 1;
    minute += 60;
  }

  hour %= 24;
  if (hour < 0) {
    hour += 24;
  }

  this->hour = hour;
  this->minute = minute;
}

clock clock::plus(int minutes) {
  return clock(this->hour, this->minute + minutes);
}

clock::operator std::string() const {
  std::string result;
  if (this->hour < 10) {
    result += "0";
  }
  result += std::to_string(hour) + ":";

  if (this->minute < 10) {
    result += "0";
  }
  result += std::to_string(minute);

  return result;
}

bool clock::operator==(const clock other) const {
  return other.hour == this->hour && other.minute == this->minute;
}

bool clock::operator!=(const clock other) const {
  return other.hour != this->hour || other.minute != this->minute;
}

} // namespace date_independent
