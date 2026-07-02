#include "meetup.h"

namespace meetup {

static boost::gregorian::date next_weekday(boost::gregorian::date start,
                                           boost::date_time::weekdays weekday) {
  int inc = weekday - start.day_of_week();
  if (inc < 0) {
    inc += 7;
  }

  return start + boost::gregorian::days(inc);
}

boost::gregorian::date
scheduler::teenth(boost::date_time::weekdays weekday) const {
  return next_weekday(boost::gregorian::date(this->year, this->month, 13),
                      weekday);
}

boost::gregorian::date
scheduler::find_nth_weekday(int nth, boost::date_time::weekdays weekday) const {
  return next_weekday(boost::gregorian::date(this->year, this->month, 1),
                      weekday) +
         boost::gregorian::days(7 * nth);
}

boost::gregorian::date
scheduler::find_last_weekday(boost::date_time::weekdays weekday) const {
  return next_weekday(boost::gregorian::date(this->year, this->month, 1) +
                          boost::gregorian::months(1) -
                          boost::gregorian::days(7),
                      weekday);
}

} // namespace meetup
