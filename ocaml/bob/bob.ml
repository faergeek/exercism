let response_for s =
  let letters, other_chars =
    String.to_seq s
    |> Seq.filter (function ' ' | '\t' | '\n' | '\r' -> false | _ -> true)
    |> Seq.partition (function 'A' .. 'Z' | 'a' .. 'z' -> true | _ -> false)
  in
  if Seq.is_empty letters && Seq.is_empty other_chars then "Fine. Be that way!"
  else
    let yelling =
      (not @@ Seq.is_empty letters)
      && Seq.for_all (function 'A' .. 'Z' -> true | _ -> false) letters
    and question =
      other_chars |> String.of_seq |> String.ends_with ~suffix:"?"
    in
    if question && yelling then "Calm down, I know what I'm doing!"
    else if question then "Sure."
    else if yelling then "Whoa, chill out!"
    else "Whatever."
