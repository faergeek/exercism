open Base

type bst = Leaf | Node of { left : bst; value : int; right : bst }

let empty = Leaf

let value node =
  match node with
  | Leaf -> Error "Leaf has no value"
  | Node node -> Ok node.value

let left node =
  match node with Leaf -> Error "Leaf has no left" | Node node -> Ok node.left

let right node =
  match node with
  | Leaf -> Error "Leaf has no right"
  | Node node -> Ok node.right

let rec insert new_value node =
  match node with
  | Leaf -> Node { left = Leaf; value = new_value; right = Leaf }
  | Node node ->
      if new_value > node.value then
        Node { node with right = insert new_value node.right }
      else Node { node with left = insert new_value node.left }

let rec to_list node =
  match node with
  | Leaf -> []
  | Node { left; value; right } -> to_list left @ (value :: to_list right)
