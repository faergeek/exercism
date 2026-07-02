#include "meetup.h"

namespace meetup {

boost::gregorian::date
scheduler::next_weekday(boost::gregorian::date start,
                        boost::date_time::weekdays weekday) const {
  int inc = weekday - start.day_of_week();
  if (inc < 0) {
    inc += 7;
  }

  return start + boost::gregorian::days(inc);
}

} // namespace meetup
