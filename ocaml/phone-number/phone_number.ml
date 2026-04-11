open Base

let number input =
  input |> String.to_list |> List.rev
  |> List.fold_result
       ~f:(fun acc c ->
         match c with
         | ' ' | '(' | ')' | '+' | '-' | '.' -> Ok acc
         | '0' .. '9' -> Ok (c :: acc)
         | 'a' .. 'z' -> Error "letters not permitted"
         | _ -> Error "punctuations not permitted")
       ~init:[]
  |> Result.bind ~f:(fun digits ->
         match List.length digits with
         | 10 -> Ok digits
         | 11 -> (
             match digits with
             | '1' :: digits -> Ok digits
             | _ -> Error "11 digits must start with 1")
         | n ->
             if n > 11 then Error "more than 11 digits"
             else Error "incorrect number of digits")
  |> Result.bind ~f:(fun digits ->
         match digits with
         | '0' :: _ -> Error "area code cannot start with zero"
         | '1' :: _ -> Error "area code cannot start with one"
         | _ :: _ :: _ :: '0' :: _ ->
             Error "exchange code cannot start with zero"
         | _ :: _ :: _ :: '1' :: _ ->
             Error "exchange code cannot start with one"
         | digits -> Ok digits)
  |> Result.map ~f:(fun digits -> digits |> String.of_list)