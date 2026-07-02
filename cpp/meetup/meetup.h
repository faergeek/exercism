#pragma once

#include <boost/date_time/gregorian/gregorian.hpp>

namespace meetup {

class scheduler {
private:
  const boost::date_time::months_of_year month;
  const int year;

  boost::gregorian::date teenth(boost::date_time::weekdays weekday) const;

  boost::gregorian::date
  find_nth_weekday(int nth, boost::date_time::weekdays weekday) const;
  boost::gregorian::date
  find_last_weekday(boost::date_time::weekdays weekday) const;

public:
  scheduler(boost::date_time::months_of_year month, int year)
      : month(month), year(year) {}

  boost::gregorian::date monteenth() const {
    return this->teenth(boost::date_time::Monday);
  }

  boost::gregorian::date tuesteenth() const {
    return this->teenth(boost::date_time::Tuesday);
  }

  boost::gregorian::date wednesteenth() const {
    return this->teenth(boost::date_time::Wednesday);
  }

  boost::gregorian::date thursteenth() const {
    return this->teenth(boost::date_time::Thursday);
  }

  boost::gregorian::date friteenth() const {
    return this->teenth(boost::date_time::Friday);
  }

  boost::gregorian::date saturteenth() const {
    return this->teenth(boost::date_time::Saturday);
  }

  boost::gregorian::date sunteenth() const {
    return this->teenth(boost::date_time::Sunday);
  }

  boost::gregorian::date first_monday() const {
    return this->find_nth_weekday(0, boost::date_time::Monday);
  }

  boost::gregorian::date first_tuesday() const {
    return this->find_nth_weekday(0, boost::date_time::Tuesday);
  }

  boost::gregorian::date first_wednesday() const {
    return this->find_nth_weekday(0, boost::date_time::Wednesday);
  }

  boost::gregorian::date first_thursday() const {
    return this->find_nth_weekday(0, boost::date_time::Thursday);
  }

  boost::gregorian::date first_friday() const {
    return this->find_nth_weekday(0, boost::date_time::Friday);
  }

  boost::gregorian::date first_saturday() const {
    return this->find_nth_weekday(0, boost::date_time::Saturday);
  }

  boost::gregorian::date first_sunday() const {
    return this->find_nth_weekday(0, boost::date_time::Sunday);
  }

  boost::gregorian::date second_monday() const {
    return this->find_nth_weekday(1, boost::date_time::Monday);
  }

  boost::gregorian::date second_tuesday() const {
    return this->find_nth_weekday(1, boost::date_time::Tuesday);
  }

  boost::gregorian::date second_wednesday() const {
    return this->find_nth_weekday(1, boost::date_time::Wednesday);
  }

  boost::gregorian::date second_thursday() const {
    return this->find_nth_weekday(1, boost::date_time::Thursday);
  }

  boost::gregorian::date second_friday() const {
    return this->find_nth_weekday(1, boost::date_time::Friday);
  }

  boost::gregorian::date second_saturday() const {
    return this->find_nth_weekday(1, boost::date_time::Saturday);
  }

  boost::gregorian::date second_sunday() const {
    return this->find_nth_weekday(1, boost::date_time::Sunday);
  }

  boost::gregorian::date third_monday() const {
    return this->find_nth_weekday(2, boost::date_time::Monday);
  }

  boost::gregorian::date third_tuesday() const {
    return this->find_nth_weekday(2, boost::date_time::Tuesday);
  }

  boost::gregorian::date third_wednesday() const {
    return this->find_nth_weekday(2, boost::date_time::Wednesday);
  }

  boost::gregorian::date third_thursday() const {
    return this->find_nth_weekday(2, boost::date_time::Thursday);
  }

  boost::gregorian::date third_friday() const {
    return this->find_nth_weekday(2, boost::date_time::Friday);
  }

  boost::gregorian::date third_saturday() const {
    return this->find_nth_weekday(2, boost::date_time::Saturday);
  }

  boost::gregorian::date third_sunday() const {
    return this->find_nth_weekday(2, boost::date_time::Sunday);
  }

  boost::gregorian::date fourth_monday() const {
    return this->find_nth_weekday(3, boost::date_time::Monday);
  }

  boost::gregorian::date fourth_tuesday() const {
    return this->find_nth_weekday(3, boost::date_time::Tuesday);
  }

  boost::gregorian::date fourth_wednesday() const {
    return this->find_nth_weekday(3, boost::date_time::Wednesday);
  }

  boost::gregorian::date fourth_thursday() const {
    return this->find_nth_weekday(3, boost::date_time::Thursday);
  }

  boost::gregorian::date fourth_friday() const {
    return this->find_nth_weekday(3, boost::date_time::Friday);
  }

  boost::gregorian::date fourth_saturday() const {
    return this->find_nth_weekday(3, boost::date_time::Saturday);
  }

  boost::gregorian::date fourth_sunday() const {
    return this->find_nth_weekday(3, boost::date_time::Sunday);
  }

  boost::gregorian::date last_monday() const {
    return this->find_last_weekday(boost::date_time::Monday);
  }

  boost::gregorian::date last_tuesday() const {
    return this->find_last_weekday(boost::date_time::Tuesday);
  }

  boost::gregorian::date last_wednesday() const {
    return this->find_last_weekday(boost::date_time::Wednesday);
  }

  boost::gregorian::date last_thursday() const {
    return this->find_last_weekday(boost::date_time::Thursday);
  }

  boost::gregorian::date last_friday() const {
    return this->find_last_weekday(boost::date_time::Friday);
  }

  boost::gregorian::date last_saturday() const {
    return this->find_last_weekday(boost::date_time::Saturday);
  }

  boost::gregorian::date last_sunday() const {
    return this->find_last_weekday(boost::date_time::Sunday);
  }
};

} // namespace meetup
