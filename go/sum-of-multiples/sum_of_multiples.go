package sumofmultiples

func SumMultiples(limit int, divisors ...int) int {
	multiples := make(map[int]struct{})

	for _, divisor := range divisors {
		if divisor < 1 {
			continue
		}

		for n := divisor; n < limit; n += divisor {
			multiples[n] = struct{}{}
		}
	}

	sum := 0
	for multiple := range multiples {
		sum += multiple
	}

	return sum
}
