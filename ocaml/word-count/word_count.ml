open Base

let word_count subtitles =
  subtitles |> String.lowercase
  |> String.split_on_chars ~on:[ ' '; '\n'; ',' ]
  |> List.map ~f:(String.strip ~drop:(Fn.non Char.is_alphanum))
  |> List.filter ~f:(Fn.non String.is_empty)
  |> List.map ~f:(fun word -> (word, 1))
  |> Map.of_alist_fold (module String) ~init:0 ~f:( + )
