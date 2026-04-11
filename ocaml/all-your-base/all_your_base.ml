type base = int

let from_base from digits =
  let rec from_base0 acc = function
    | [] -> Some acc
    | x :: xs ->
        if x >= 0 && x < from then from_base0 ((acc * from) + x) xs else None
  in
  from_base0 0 digits

let to_base target = function
  | 0 -> [ 0 ]
  | value ->
      let rec to_base0 digits = function
        | 0 -> digits
        | value ->
            (to_base0 [@tailcall])
              ((value mod target) :: digits)
              (value / target)
      in
      to_base0 [] value

let convert_bases ~from ~digits ~target =
  let validate_base base = if base < 2 then None else Some base in
  match (validate_base from, validate_base target) with
  | Some from, Some target ->
      from_base from digits |> Option.map (to_base target)
  | _ -> None
