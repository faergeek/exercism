package linkedlist

import "errors"

type Node[T comparable] struct {
	Value      T
	next, prev *Node[T]
}

type List[T comparable] struct {
	first *Node[T]
	last  *Node[T]
}

// NewNode constructs a new List with given elements.
func NewList[T comparable](elements ...T) *List[T] {
	list := &List[T]{}
	for _, el := range elements {
		list.Push(el)
	}
	return list
}

// Next returns a pointer to the next node in the linked list.
func (n *Node[T]) Next() *Node[T] {
	return n.next
}

// Prev returns a pointer to the previous node in the linked list.
func (n *Node[T]) Prev() *Node[T] {
	return n.prev
}

// Unshift pushes a new value before head.
func (ll *List[T]) Unshift(v T) {
	newNode := &Node[T]{next: ll.first, Value: v}
	if ll.first == nil {
		ll.first = newNode
		ll.last = newNode
	} else {
		ll.first.prev = newNode
		ll.first = newNode
	}
}

// Push pushes a new value after tail.
func (ll *List[T]) Push(v T) {
	if ll.last == nil {
		newNode := &Node[T]{Value: v}
		ll.first = newNode
		ll.last = newNode
	} else {
		newNode := &Node[T]{prev: ll.last, Value: v}
		ll.last.next = newNode
		ll.last = newNode
	}
}

// Shift pops the element at head. It returns error if the linked list is empty.
func (ll *List[T]) Shift() (T, error) {
	var value T
	if ll.first == nil {
		return value, errors.New("list is empty")
	}

	value = ll.first.Value
	ll.first = ll.first.next

	if ll.first == nil {
		ll.last = nil
	} else {
		ll.first.prev = nil
	}

	return value, nil
}

// Pop pops the element at tail. It returns error if the linked list is empty.
func (ll *List[T]) Pop() (T, error) {
	var value T
	if ll.last == nil {
		return value, errors.New("list is empty")
	}

	value = ll.last.Value
	ll.last = ll.last.prev

	if ll.last == nil {
		ll.first = nil
	} else {
		ll.last.next = nil
	}

	return value, nil
}

// Reverse reverses the given linked list in-place.
func (ll *List[T]) Reverse() {
	for node := ll.first; node != nil; node = node.prev {
		node.prev, node.next = node.next, node.prev
	}
	ll.first, ll.last = ll.last, ll.first
}

// First returns a pointer to the first node in the linked list (head).
func (ll *List[T]) First() *Node[T] {
	return ll.first
}

// Last returns a pointer to the last node in the linked list (tail).
func (ll *List[T]) Last() *Node[T] {
	return ll.last
}

// Count returns the number of nodes in the list.
func (ll *List[T]) Count() int {
	count := 0
	for node := ll.first; node != nil; node = node.next {
		count++
	}
	return count
}

// Delete removes the first node in a list with a given value.
// Returns true if a node was removed.
func (ll *List[T]) Delete(v T) bool {
	for node := ll.first; node != nil; node = node.next {
		if node.Value != v {
			continue
		}

		if node == ll.first {
			ll.first = node.next
		}

		if node == ll.last {
			ll.last = node.prev
		}

		if node.prev != nil {
			node.prev.next = node.next
		}

		if node.next != nil {
			node.next.prev = node.prev
		}

		return true
	}

	return false
}
