package isbnverifier

func IsValidISBN(isbn string) bool {
	nums := make([]byte, 0, 10)
	for i := 0; i < len(isbn); i++ {
		if isbn[i] >= '0' && isbn[i] <= '9' {
			nums = append(nums, isbn[i]-'0')
		} else if i == len(isbn)-1 && isbn[i] == 'X' {
			nums = append(nums, 10)
		} else if isbn[i] != '-' {
			return false
		}
	}

	if len(nums) != 10 {
		return false
	}

	sum := 0
	for i, n := range nums {
		sum += int(n) * (10 - i)
	}

	return sum%11 == 0
}
