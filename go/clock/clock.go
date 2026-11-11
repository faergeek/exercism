package clock

import "fmt"

type Clock struct {
	minutes int
}

const minutesInDay = 24 * 60

func fromMinutes(m int) Clock {
	m %= minutesInDay

	if m < 0 {
		m += minutesInDay
	}

	return Clock{minutes: m}
}

func New(h, m int) Clock {
	return fromMinutes(h*60 + m)
}

func (c Clock) Add(m int) Clock {
	return fromMinutes(c.minutes + m)
}

func (c Clock) Subtract(m int) Clock {
	return fromMinutes(c.minutes - m)
}

func (c Clock) String() string {
	return fmt.Sprintf(
		"%02d:%02d",
		c.minutes/60, c.minutes%60,
	)
}
