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

// FromPov returns the pov from the node specified in the argument.
func (tr *Tree) FromPov(from string) *Tree {
	p := findPath(tr, from)
	if len(p) == 0 {
		return nil
	}

	for i, pathNode := range p[:len(p)-1] {
		var newParent *Tree
		if i > 0 {
			newParent = p[i-1]
		}

		nextPathNode := p[i+1]

		if pathNode.first == nextPathNode {
			pathNode.parent = newParent
			pathNode.first = pathNode.first.next
			pathNode.next = nextPathNode.first

			nextPathNode.first = pathNode
		} else {
			for prev := pathNode.first; prev != nil; prev = prev.next {
				if prev.next == nextPathNode {
					pathNode.parent = newParent
					pathNode.next = nextPathNode.first

					prev.next = prev.next.next
					nextPathNode.first = pathNode
					break
				}
			}
		}
	}

	result := p[len(p)-1]
	result.parent = nil

	return result
}

// PathTo returns the shortest path between two nodes in the tree.
func (tr *Tree) PathTo(from, to string) []string {
	fromPath := findPath(tr, from)
	toPath := findPath(tr, to)

	lca := -1
	for i := range min(len(fromPath), len(toPath)) {
		if fromPath[i] != toPath[i] {
			break
		}

		lca = i
	}

	if lca == -1 {
		return nil
	}

	result := make([]string, len(fromPath)+len(toPath))
	l := 0

	for j := len(fromPath) - 1; j > lca; j-- {
		result[l] = fromPath[j].value
		l++
	}

	for j := lca; j < len(toPath); j++ {
		result[l] = toPath[j].value
		l++
	}

	return result[:l]
}
