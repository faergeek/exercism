package scrabblescore

var arr = [26]int{1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10}

func Score(word string) int {
	score := 0

	for i := 0; i < len(word); i++ {
		b := word[i]
		if b >= 'a' && b <= 'z' {
			score += arr[b-'a']
		} else {
			score += arr[b-'A']
		}
	}

	return score
}
