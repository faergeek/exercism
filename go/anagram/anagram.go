package anagram

import "strings"

func countRunes(s string) map[rune]int {
	counts := make(map[rune]int)

	for _, r := range s {
		counts[r]++
	}

	return counts
}

func Detect(subject string, candidates []string) []string {
	lcSubject := strings.ToLower(subject)
	subjCounts := countRunes(lcSubject)

	var result []string
outer:
	for _, candidate := range candidates {
		if len(candidate) != len(subject) {
			continue
		}

		lcCandidate := strings.ToLower(candidate)
		if lcCandidate == lcSubject {
			continue
		}

		counts := countRunes(lcCandidate)

		for r, c := range counts {
			if subjCounts[r] != c {
				continue outer
			}
		}

		result = append(result, candidate)
	}

	return result
}
