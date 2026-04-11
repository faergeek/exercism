let valid input =
  let number =
    input |> String.to_seq |> Seq.filter (fun c -> c != ' ') |> List.of_seq
  in
  if not @@ List.for_all (fun c -> c >= '0' && c <= '9') number then false
  else if List.length number < 2 then false
  else
    let sum =
      number |> List.rev
      |> List.mapi (fun i c ->
             let n = Char.code c - Char.code '0' in
             if i mod 2 = 1 then
               let n = n * 2 in
               if n > 9 then n - 9 else n
             else n)
      |> List.fold_left ( + ) 0
    in
    sum mod 10 = 0
