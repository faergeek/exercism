package bafflingbirthdays

import (
	"math"
	"math/rand"
	"time"
)

func SharedBirthday(dates []time.Time) bool {
	seen := make([]bool, 31*12)
	for _, date := range dates {
		key := int(date.Day()) + int(date.Month())*12 - 1
		if seen[key] {
			return true
		}

		seen[key] = true
	}

	return false
}

func RandomBirthdates(size int) []time.Time {
	result := make([]time.Time, size)

	for i := range size {
		date := time.Unix(rand.Int63(), 0)
		year := date.Year()

		for year%4 == 0 && year%100 != 0 || year%400 == 0 {
			date = time.Unix(rand.Int63(), 0)
			year = date.Year()
		}

		result[i] = date
	}

	return result
}

func EstimatedProbability(size int) float64 {
	num := 1.0
	for n := 365 - size + 1; n <= 365; n++ {
		num *= float64(n)
	}

	return 100 * (1 - float64(num)/math.Pow(365, float64(size)))
}
