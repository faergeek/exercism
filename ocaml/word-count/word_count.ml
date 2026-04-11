open Base

let word_count subtitles =
  String.split_lines subtitles
  |> List.bind ~f:(fun word -> String.split_on_chars ~on:[ ' '; ',' ] word)
  |> List.map ~f:(fun word ->
         let len = String.length word in
         word |> String.lowercase |> String.to_list
         |> List.filteri ~f:(fun i c ->
                Char.to_int c >= Char.to_int 'a'
                && Char.to_int c <= Char.to_int 'z'
                || Char.to_int c >= Char.to_int '0'
                   && Char.to_int c <= Char.to_int '9'
                || (Char.to_int c = Char.to_int '\'' && i <> 0 && i <> len - 1))
         |> String.of_char_list)
  |> List.filter ~f:(fun word -> String.length word <> 0)
  |> List.fold
       ~f:(fun acc word ->
         let count =
           match Map.find acc word with None -> 0 | Some count -> count
         in
         Map.set ~key:word ~data:(count + 1) acc)
       ~init:(Map.empty (module String))
