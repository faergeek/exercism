package pov

type Tree struct {
	value  string
	parent *Tree
	first  *Tree
	next   *Tree
}

// New creates and returns a new Tree with the given root value and children.
func New(value string, children ...*Tree) *Tree {
	tr := &Tree{value: value}

	if len(children) != 0 {
		tr.first = children[0]
	}

	for i, child := range children {
		child.parent = tr

		if i < len(children)-1 {
			child.next = children[i+1]
		}
	}

	return tr
}

// Value returns the value at the root of a tree.
func (tr *Tree) Value() string {
	return tr.value
}

// Children returns a slice containing the children of a tree.
func (tr *Tree) Children() []*Tree {
	var children []*Tree

	for node := tr.first; node != nil; node = node.next {
		children = append(children, node)
	}

	return children
}

// String describes a tree in a compact S-expression format.
func (tr *Tree) String() string {
	if tr == nil {
		return "nil"
	}
	result := tr.Value()
	if len(tr.Children()) == 0 {
		return result
	}
	for _, ch := range tr.Children() {
		result += " " + ch.String()
	}
	return "(" + result + ")"
}

func findPath(tr *Tree, value string) []*Tree {
	depth := 1

	node := tr
	for node != nil {
		if node.value == value {
			p := make([]*Tree, depth)
			for i := len(p) - 1; i > -1; i-- {
				p[i] = node
				node = node.parent
			}
			return p
		}

		if node.first != nil {
			depth++
			node = node.first
		} else if node.next != nil {
			node = node.next
		} else {
			if node.parent == nil {
				break
			}

			depth--
			node = node.parent.next
		}
	}

	return nil
}

func (tr *Tree) removeChild(child *Tree) {
	for it := &tr.first; *it != nil; it = &(*it).next {
		if (*it) == child {
			(*it) = child.next
			break
		}
	}

	child.parent = nil
	child.next = nil
}

func (tr *Tree) addChild(child *Tree) {
	child.parent = tr
	child.next = tr.first
	tr.first = child
}

// FromPov returns the pov from the node specified in the argument.
func (tr *Tree) FromPov(from string) *Tree {
	p := findPath(tr, from)
	if len(p) == 0 {
		return nil
	}

	for i := 0; i < len(p)-1; i++ {
		parent := p[i]
		child := p[i+1]

		child.addChild(parent)
		parent.removeChild(child)
	}

	return p[len(p)-1]
}

// PathTo returns the shortest path between two nodes in the tree.
func (tr *Tree) PathTo(from, to string) []string {
	p := findPath(tr.FromPov(from), to)
	result := make([]string, len(p))
	l := 0

	for i := range p {
		result[l] = p[i].value
		l++
	}

	return result
}
