open Base

let encode input =
  let rec encode0 prev acc input =
    match input with
    | ch :: remainder -> (
        match prev with
        | None -> (encode0 [@tailcall]) (Some (ch, 1)) acc remainder
        | Some (prev_ch, repeat_count) ->
            if Char.equal ch prev_ch then
              (encode0 [@tailcall]) (Some (ch, repeat_count + 1)) acc remainder
            else
              (encode0 [@tailcall])
                (Some (ch, 1))
                ((prev_ch, repeat_count) :: acc)
                remainder)
    | [] ->
        (match prev with None -> acc | Some x -> x :: acc)
        |> List.bind ~f:(function
             | ch, 1 -> [ ch ]
             | ch, n -> ch :: List.rev (n |> Int.to_string |> String.to_list))
        |> List.rev |> String.of_list
  in
  input |> String.to_list |> encode0 None []

let decode input =
  let rec decode0 acc digits input =
    match input with
    | ('0' .. '9' as digit) :: remainder ->
        (decode0 [@tailcall]) acc (digit :: digits) remainder
    | ch :: remainder -> (
        match digits with
        | [] -> (decode0 [@tailcall]) (ch :: acc) [] remainder
        | digits ->
            let rep_count =
              digits |> List.rev |> String.of_list |> Int.of_string
            in
            let repeated =
              Sequence.repeat ch
              |> (Fn.flip Sequence.take) rep_count
              |> Sequence.to_list
            in
            (decode0 [@tailcall]) (repeated @ acc) [] remainder)
    | [] -> List.rev acc |> String.of_list
  in
  input |> String.to_list |> decode0 [] []
