let acronym str =
  String.to_seq str
  |> Seq.filter_map (fun ch ->
         let upper_ch = Char.uppercase_ascii ch in
         match upper_ch with
         | 'A' .. 'Z' -> Some upper_ch
         | ' ' | '-' -> Some ' '
         | _ -> None)
  |> String.of_seq |> String.split_on_char ' ' |> List.to_seq
  |> Seq.filter_map (fun s ->
         match String.get s 0 with
         | ch -> Some ch
         | exception Invalid_argument _ -> None)
  |> String.of_seq
