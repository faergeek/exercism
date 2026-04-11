let recite from count =
  let rec recite0 from until verses =
    if until > from then verses
    else
      let recite_verse n =
        match n with
        | 0 ->
            "No more bottles of beer on the wall, no more bottles of beer.\n\
             Go to the store and buy some more, 99 bottles of beer on the wall."
        | n ->
            let pluralize_bottle_count = function
              | 0 -> "no more bottles"
              | 1 -> "1 bottle"
              | n -> Printf.sprintf "%i bottles" n
            in
            Printf.sprintf
              "%s of beer on the wall, %s of beer.\n\
               Take %s down and pass it around, %s of beer on the wall."
              (pluralize_bottle_count n) (pluralize_bottle_count n)
              (if n == 1 then "it" else "one")
              (pluralize_bottle_count (n - 1))
      in
      (recite0 [@tailcall]) from (until + 1) (recite_verse until :: verses)
  in
  String.concat "\n\n" @@ recite0 from (from - count + 1) []
