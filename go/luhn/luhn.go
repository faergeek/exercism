package luhn

func Valid(id string) bool {
	nums := make([]byte, 0)
	odd := false
	for i := len(id) - 1; i > -1; i-- {
		if id[i] < '0' || id[i] > '9' {
			if id[i] == ' ' {
				continue
			}

			return false
		}

		n := id[i] - '0'

		if odd {
			n <<= 1
			if n > 9 {
				n -= 9
			}
		}

		nums = append(nums, n)
		odd = !odd
	}

	if len(nums) <= 1 {
		return false
	}

	var sum byte = 0
	for _, n := range nums {
		sum = (sum + n) % 10
	}

	return sum == 0
}
