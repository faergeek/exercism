let init_list n = List.init n (fun x -> x + 1)
let sum_list = List.fold_left (fun s x -> s + x) 0
let square x = x * x

let square_of_sum n =
  let sum = init_list n |> sum_list in
  sum * sum

let sum_of_squares n = init_list n |> List.map square |> sum_list
let difference_of_squares n = square_of_sum n - sum_of_squares n
