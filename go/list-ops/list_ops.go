package listops

// IntList is an abstraction of a list of integers which we can define methods on
type IntList []int

func (s IntList) Foldl(fn func(int, int) int, initial int) int {
	acc := initial

	for _, x := range s {
		acc = fn(acc, x)
	}

	return acc
}

func (s IntList) Foldr(fn func(int, int) int, initial int) int {
	acc := initial

	for i := len(s) - 1; i > -1; i-- {
		acc = fn(s[i], acc)
	}

	return acc
}

func (s IntList) Filter(fn func(int) bool) IntList {
	out := make([]int, len(s))

	i := 0
	for _, x := range s {
		if fn(x) {
			out[i] = x
			i++
		}
	}

	return out[:i]
}

func (s IntList) Length() int {
	return len(s)
}

func (s IntList) Map(fn func(int) int) IntList {
	out := make([]int, len(s))

	for i, x := range s {
		out[i] = fn(x)
	}

	return out
}

func (s IntList) Reverse() IntList {
	out := make([]int, len(s))

	for i, x := range s {
		out[len(s)-1-i] = x
	}

	return out
}

func (s IntList) Append(lst IntList) IntList {
	if s.Length() == 0 {
		return lst
	}

	out := make([]int, s.Length()+lst.Length())

	i := 0
	for i < len(s) {
		out[i] = s[i]
		i++
	}

	for i, j := i, 0; j < len(lst); i, j = i+1, j+1 {
		out[i] = lst[j]
	}

	return out
}

func (s IntList) Concat(lists []IntList) IntList {
	l := 0
	for _, list := range lists {
		l += len(list)
	}

	out := make([]int, l)

	i := 0
	for _, list := range lists {
		for _, x := range list {
			out[i] = x
			i++
		}
	}

	return out
}
