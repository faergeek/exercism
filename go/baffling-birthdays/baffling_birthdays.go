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
	base := time.Date(1999, 1, 1, 0, 0, 0, 0, &time.Location{})

	for i := range size {
		result[i] = base.Add(time.Hour * 24 * time.Duration(rand.Intn(365)))
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
