type palindrome_products = { value : int option; factors : (int * int) list }

let digits_ltr n =
  Seq.unfold
    (fun (x, divisor) ->
      if divisor = 0 then None
      else Some (x / divisor, (x mod divisor, divisor / 10)))
    (n, n |> Float.of_int |> log10 |> Float.floor |> ( ** ) 10.0 |> Int.of_float)

let digits_rtl n =
  Seq.unfold (fun x -> if x = 0 then None else Some (x mod 10, x / 10)) n

let is_a_palindrome_number n =
  Seq.for_all2 Int.equal (digits_ltr n) (digits_rtl n)

module IntMap = Map.Make (Int)

let find_products min max pick_binding =
  if min > max then Error "min must be <= max"
  else
    let rec get_all_products x y acc =
      if x > max then acc
      else if y > x then get_all_products (x + 1) min acc
      else
        let value = x * y in
        if is_a_palindrome_number value then
          let factors = if x < y then (x, y) else (y, x) in
          get_all_products x (y + 1) (IntMap.add_to_list value factors acc)
        else get_all_products x (y + 1) acc
    in
    Ok
      (match get_all_products min min IntMap.empty |> pick_binding with
      | None -> { value = None; factors = [] }
      | Some (value, factors) -> { value = Some value; factors })

let smallest ~min ~max = find_products min max IntMap.min_binding_opt
let largest ~min ~max = find_products min max IntMap.max_binding_opt
