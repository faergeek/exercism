type palindrome_products = { value : int option; factors : (int * int) list }

let range ~min ~max = Seq.ints min |> Seq.take (max - min + 1)

let digits_seq_left n =
  Seq.unfold
    (fun (x, divisor) ->
      if divisor = 0 then None
      else Some (x / divisor, (x mod divisor, divisor / 10)))
    (n, n |> Float.of_int |> log10 |> Float.floor |> ( ** ) 10.0 |> Int.of_float)

let digits_seq_right n =
  Seq.unfold (fun x -> if x = 0 then None else Some (x mod 10, x / 10)) n

let is_a_palindrome_number n =
  Seq.for_all2 ( = ) (digits_seq_left n) (digits_seq_right n)

module IntMap = Map.Make (Int)

let find_palindrome_products ~min ~max ~compare =
  if min > max then Error "min must be <= max"
  else
    let { value; factors } =
      let xs = range ~min ~max in
      xs
      |> Seq.map (fun x ->
             xs
             |> Seq.filter_map (fun y ->
                    if is_a_palindrome_number (x * y) then
                      Some (if x < y then (x, y) else (y, x))
                    else None))
      |> Seq.concat |> List.of_seq
      |> List.sort_uniq (fun (x0, x1) (y0, y1) ->
             match Int.compare x0 y0 with 0 -> Int.compare x1 y1 | c -> c)
      |> List.fold_left
           (fun acc (x, y) ->
             let n = x * y in
             match IntMap.find_opt n acc with
             | None -> IntMap.add n [ (x, y) ] acc
             | Some factors -> IntMap.add n ((x, y) :: factors) acc)
           IntMap.empty
      |> IntMap.to_seq
      |> Seq.fold_left
           (fun acc (value, factors) ->
             match acc.value with
             | None -> { value = Some value; factors }
             | Some prevValue ->
                 if compare value prevValue then { value = Some value; factors }
                 else acc)
           { value = None; factors = [] }
    in
    Ok { value; factors = List.rev factors }

let smallest ~min ~max = find_palindrome_products ~min ~max ~compare:( < )
let largest ~min ~max = find_palindrome_products ~min ~max ~compare:( > )
