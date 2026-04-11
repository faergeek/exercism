let primes max =
  let module IntSet = Set.Make (Int) in
  let xs = List.init (max - 1) (fun x -> x + 2) |> IntSet.of_list in
  xs
  |> IntSet.fold
       (fun x set ->
         let rec loop xn max set =
           if xn > max then set else IntSet.remove xn set |> loop (xn + x) max
         in
         loop (x + x) max set)
       xs
  |> IntSet.to_list
