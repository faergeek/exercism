let raindrop n =
  match (n mod 3 = 0, n mod 5 = 0, n mod 7 = 0) with
  | false, false, false -> string_of_int n
  | pling, plang, plong ->
      let f b s = if b then s else "" in
      f pling "Pling" ^ f plang "Plang" ^ f plong "Plong"
