let factors_of n =
  let ( % ) = Int64.rem and ( + ) = Int64.add and ( / ) = Int64.div in
  let rec factors_of0 n divisor result =
    if n < 2L then result
    else if n % divisor = 0L then
      factors_of0 (n / divisor) divisor (divisor :: result)
    else factors_of0 n (divisor + 1L) result
  in
  factors_of0 n 2L [] |> List.rev
