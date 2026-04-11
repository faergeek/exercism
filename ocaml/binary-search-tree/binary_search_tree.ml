open Base

type bst = Leaf | Node of (bst * int * bst)

let empty = Leaf

let value node =
  match node with Leaf -> Error "Leaf has no value" | Node (_, v, _) -> Ok v

let left node =
  match node with Leaf -> Error "Leaf has no left" | Node (l, _, _) -> Ok l

let right node =
  match node with Leaf -> Error "Leaf has no right" | Node (_, _, r) -> Ok r

let rec insert new_value node =
  match node with
  | Leaf -> Node (Leaf, new_value, Leaf)
  | Node (l, v, r) ->
      if new_value > v then Node (l, v, insert new_value r)
      else Node (insert new_value l, v, r)

let rec to_list node =
  match node with Leaf -> [] | Node (l, v, r) -> to_list l @ (v :: to_list r)
