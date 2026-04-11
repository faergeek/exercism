type base = int

let fold_opt_list f init list =
  let rec fold_opt_list0 acc list index =
    match list with
    | [] -> Some acc
    | x :: xs -> (
        match f acc index x with
        | Some new_init -> (fold_opt_list0 [@tailcall]) new_init xs (index + 1)
        | None -> None)
  in
  fold_opt_list0 init list 0

let from_base from digits =
  let digit_value index digit =
    if digit >= 0 && digit < from then
      let multiplier = Int.of_float Float.(of_int from ** of_int index) in
      Some (digit * multiplier)
    else None
  in
  digits |> List.rev
  |> fold_opt_list
       (fun acc index digit ->
         digit_value index digit |> Option.map (( + ) acc))
       0

let to_base target = function
  | 0 -> [ 0 ]
  | value ->
      let rec to_base0 digits index = function
        | 0 -> digits
        | value ->
            (to_base0 [@tailcall])
              ((value mod target) :: digits)
              (index + 1) (value / target)
      in
      to_base0 [] 0 value

let convert_bases ~from ~digits ~target =
  let validate_base base = if base < 2 then None else Some base in
  match (validate_base from, validate_base target) with
  | Some from, Some target ->
      from_base from digits |> Option.map (to_base target)
  | _ -> None