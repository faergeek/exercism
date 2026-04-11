let init_list n = List.init n (fun x -> x + 1)
let sum_list = List.fold_left (fun s x -> s + x) 0
let square x = x * x

let square_of_sum n =
  let list = init_list n in
  let sum = sum_list list in
  sum * sum

let sum_of_squares n =
  let list = init_list n in
  let squares = List.map square list in
  sum_list squares

let difference_of_squares n = square_of_sum n - sum_of_squares n
