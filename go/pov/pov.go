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

func (tr *Tree) removeChild(child *Tree) {
	for it := &tr.first; *it != nil; it = &(*it).next {
		if (*it) == child {
			(*it) = child.next
			child.next = nil
			child.parent = nil
			break
		}
	}
}

func (tr *Tree) addChild(child *Tree) {
	child.parent = tr
	child.next = tr.first
	tr.first = child
}

func (tr *Tree) find(value string, depth *int) *Tree {
	if depth == nil {
		var d int
		depth = &d
	} else {
	}

	*depth = 1

	for {
		if tr == nil {
			return nil
		}

		if tr.value == value {
			return tr
		}

		if tr.first != nil {
			*depth++
			tr = tr.first
		} else if tr.next != nil {
			tr = tr.next
		} else if tr.parent != nil {
			*depth--
			tr = tr.parent.next
		} else {
			return nil
		}
	}
}

// FromPov returns the pov from the node specified in the argument.
func (tr *Tree) FromPov(from string) *Tree {
	root := tr.find(from, nil)
	if root == nil {
		return nil
	}

	for child, parent := root, root.parent; parent != nil; {
		grandparent := parent.parent
		if grandparent != nil {
			grandparent.removeChild(parent)
		}

		parent.removeChild(child)
		child.addChild(parent)

		child = parent
		parent = grandparent
	}

	return root
}

// PathTo returns the shortest path between two nodes in the tree.
func (tr *Tree) PathTo(from, to string) []string {
	depth := 1
	toNode := tr.FromPov(from).find(to, &depth)
	if toNode == nil {
		return nil
	}

	result := make([]string, depth)
	for i := len(result) - 1; toNode != nil; i, toNode = i-1, toNode.parent {
		result[i] = toNode.value
	}

	return result
}
