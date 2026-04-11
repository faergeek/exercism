open Base

let in_english n =
  let rec in_english0 = function
    | 0L -> Ok "zero"
    | 1L -> Ok "one"
    | 2L -> Ok "two"
    | 3L -> Ok "three"
    | 4L -> Ok "four"
    | 5L -> Ok "five"
    | 6L -> Ok "six"
    | 7L -> Ok "seven"
    | 8L -> Ok "eight"
    | 9L -> Ok "nine"
    | 10L -> Ok "ten"
    | 11L -> Ok "eleven"
    | 12L -> Ok "twelve"
    | 13L -> Ok "thirteen"
    | 14L -> Ok "fourteen"
    | 15L -> Ok "fifteen"
    | 16L -> Ok "sixteen"
    | 17L -> Ok "seventeen"
    | 18L -> Ok "eighteen"
    | 19L -> Ok "nineteen"
    | n ->
        let open Int64 in
        let add_divisor_suffix suffix divisor =
          in_english0 (n / divisor)
          |> Result.map ~f:(fun prefix ->
                 (let n = rem n divisor in
                  if rem n divisor = 0L then Ok ""
                  else Result.map ~f:(fun x -> " " ^ x) (in_english0 n))
                 |> Result.map ~f:(fun other -> prefix ^ " " ^ suffix ^ other))
          |> Result.join
        in
        if n < 0L || n >= 1_000_000_000_000L then Error "input out of range"
        else if n >= 1_000_000_000L then
          add_divisor_suffix "billion" 1_000_000_000L
        else if n >= 1_000_000L then add_divisor_suffix "million" 1_000_000L
        else if n >= 1_000L then add_divisor_suffix "thousand" 1_000L
        else if n >= 100L then add_divisor_suffix "hundred" 100L
        else
          let prefix =
            match n / 10L with
            | 2L -> "twenty"
            | 3L -> "thirty"
            | 4L -> "forty"
            | 5L -> "fifty"
            | 6L -> "sixty"
            | 7L -> "seventy"
            | 8L -> "eighty"
            | 9L -> "ninety"
            | _ -> failwith "UNEXPECTED"
          in
          let n = rem n 10L in
          if n = 0L then Ok prefix
          else Result.map ~f:(fun x -> prefix ^ "-" ^ x) (in_english0 n)
  in
  in_english0 n
