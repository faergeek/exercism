package armstrongnumbers

func IsNumber(n int) bool {
	count := 1
	for m := 10; m <= n; m *= 10 {
		count++
	}

	sum := 0
	ncopy := n
	for i := 0; i < count; i++ {
		p := ncopy % 10
		ncopy /= 10

		a := p
		for i := 1; i < count; i++ {
			a *= p
		}

		sum += a
	}

	return sum == n
}
