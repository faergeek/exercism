#pragma once

#include <boost/date_time/gregorian/gregorian.hpp>

namespace meetup {

class scheduler {
private:
  boost::gregorian::date start;
  boost::gregorian::date next_weekday(boost::gregorian::date start,
                                      boost::date_time::weekdays weekday) const;

public:
  scheduler(boost::date_time::months_of_year month, int year) {
    this->start = boost::gregorian::date(year, month, 1);
  }

#define DEFINE_WEEKDAY_METHODS(prefix, weekday)                                \
  boost::gregorian::date prefix##teenth() const {                              \
    return next_weekday(start + boost::gregorian::days(12),                    \
                        boost::date_time::weekday);                            \
  }                                                                            \
                                                                               \
  boost::gregorian::date first_##prefix##day() const {                         \
    return next_weekday(start, boost::gregorian::weekday);                     \
  }                                                                            \
                                                                               \
  boost::gregorian::date second_##prefix##day() const {                        \
    return next_weekday(start + boost::gregorian::weeks(1),                    \
                        boost::gregorian::weekday);                            \
  }                                                                            \
                                                                               \
  boost::gregorian::date third_##prefix##day() const {                         \
    return next_weekday(start + boost::gregorian::weeks(2),                    \
                        boost::gregorian::weekday);                            \
  }                                                                            \
                                                                               \
  boost::gregorian::date fourth_##prefix##day() const {                        \
    return next_weekday(start + boost::gregorian::weeks(3),                    \
                        boost::gregorian::weekday);                            \
  }                                                                            \
                                                                               \
  boost::gregorian::date last_##prefix##day() const {                          \
    return next_weekday(start + boost::gregorian::months(1) -                  \
                            boost::gregorian::days(7),                         \
                        boost::date_time::weekday);                            \
  }

  DEFINE_WEEKDAY_METHODS(mon, Monday)
  DEFINE_WEEKDAY_METHODS(tues, Tuesday)
  DEFINE_WEEKDAY_METHODS(wednes, Wednesday)
  DEFINE_WEEKDAY_METHODS(thurs, Thursday)
  DEFINE_WEEKDAY_METHODS(fri, Friday)
  DEFINE_WEEKDAY_METHODS(satur, Saturday)
  DEFINE_WEEKDAY_METHODS(sun, Sunday)

#undef DEFINE_WEEKDAY_METHODS
};

} // namespace meetup
