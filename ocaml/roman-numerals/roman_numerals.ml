open Base

let to_roman input =
  let make_numerals whole whole_char half_char tenth_char =
    let half = whole / 2 and tenth = whole / 10 in
    [
      ([ whole_char ], whole);
      ([ whole_char; tenth_char ], whole - tenth);
      ([ half_char ], half);
      ([ half_char; tenth_char ], half - tenth);
    ]
  in
  let rec to_roman0 input acc numerals =
    if input = 0 then acc |> List.rev |> String.of_list
    else
      let chars, value = List.hd_exn numerals in
      if input >= value then to_roman0 (input - value) (chars @ acc) numerals
      else to_roman0 input acc (List.tl_exn numerals)
  in
  to_roman0 input []
    (make_numerals 1000 'M' 'D' 'C'
    @ make_numerals 100 'C' 'L' 'X'
    @ make_numerals 10 'X' 'V' 'I'
    @ [ ([ 'I' ], 1) ])
