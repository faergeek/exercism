package clock

import "fmt"

type Clock struct {
	hours   int
	minutes int
}

const hoursInDay = 24
const minutesInHour = 60
const minutesInDay = hoursInDay * minutesInHour

func New(h, m int) Clock {
	h += m / minutesInHour
	m %= minutesInHour

	if m < 0 {
		h--
		m += minutesInHour
	}

	h %= hoursInDay
	if h < 0 {
		h += hoursInDay
	}

	return Clock{hours: h, minutes: m}
}

func (c Clock) Add(m int) Clock {
	return New(c.hours, c.minutes+m)
}

func (c Clock) Subtract(m int) Clock {
	return New(c.hours, c.minutes-m)
}

func (c Clock) String() string {
	return fmt.Sprintf(
		"%02d:%02d",
		c.hours, c.minutes,
	)
}
