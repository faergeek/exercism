open Base

let is_pangram sentence =
  sentence |> String.to_list
  |> List.fold
       ~init:(Set.empty (module Char))
       ~f:(fun acc char ->
         match Char.lowercase char with
         | 'a' .. 'z' as letter -> Set.add acc letter
         | _ -> acc)
  |> Set.length
  = Char.to_int 'z' - Char.to_int 'a' + 1
