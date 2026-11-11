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
	m = h*minutesInHour + m
	m %= minutesInDay

	if m < 0 {
		m += minutesInDay
	}

	return Clock{hours: m / 60, minutes: m % 60}
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
