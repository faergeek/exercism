package darts

func Score(x, y float64) int {
	switch d := x*x + y*y; {
	case d > 100:
		return 0
	case d > 25:
		return 1
	case d > 1:
		return 5
	default:
		return 10
	}
}
