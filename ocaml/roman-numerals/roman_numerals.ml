open Base

let to_roman input =
  let numerals =
    let make_numerals whole whole_char half_char tenth_char =
      let half = whole / 2 and tenth = whole / 10 in
      [
        ([ whole_char ], whole);
        ([ whole_char; tenth_char ], whole - tenth);
        ([ half_char ], half);
        ([ half_char; tenth_char ], half - tenth);
      ]
    in
    make_numerals 1000 'M' 'D' 'C'
    @ make_numerals 100 'C' 'L' 'X'
    @ make_numerals 10 'X' 'V' 'I'
    @ [ ([ 'I' ], 1) ]
  in
  let rec produce_digits (input, digits) (chars, value) =
    if input >= value then
      produce_digits (input - value, chars @ digits) (chars, value)
    else (input, digits)
  in
  List.fold ~init:(input, []) ~f:produce_digits numerals
  |> snd |> List.rev |> String.of_list
