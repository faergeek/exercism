module CharMap = Map.Make (Char)
module CharSet = Set.Make (Char)

let brackets = CharMap.(empty |> add '(' ')' |> add '[' ']' |> add '{' '}')

let all_brackets =
  brackets |> CharMap.to_seq
  |> Seq.flat_map (fun (o, c) -> [ o; c ] |> List.to_seq)
  |> CharSet.of_seq

let is_a_bracket c = CharSet.mem c all_brackets

let are_balanced input =
  let rec match_brackets stack = function
    | [] -> List.is_empty stack
    | c :: cs -> (
        if CharMap.mem c brackets then match_brackets (c :: stack) cs
        else
          match stack with
          | [] -> false
          | b :: bs ->
              if c = CharMap.find b brackets then match_brackets bs cs
              else false)
  in
  input |> String.to_seq |> Seq.filter is_a_bracket |> List.of_seq
  |> match_brackets []
