let length xs =
  let rec length0 ?(acc = 0) = function
    | [] -> acc
    | _ :: xs -> (length0 [@tailcall]) ~acc:(acc + 1) xs
  in
  length0 xs

let reverse xs =
  let rec reverse0 ?(acc = []) = function
    | [] -> acc
    | x :: xs -> (reverse0 [@tailcall]) ~acc:(x :: acc) xs
  in
  reverse0 xs

let map ~f xs =
  let rec map0 ?(acc = []) = function
    | [] -> reverse acc
    | x :: xs -> (map0 [@tailcall]) ~acc:(f x :: acc) xs
  in
  map0 xs

let filter ~f xs =
  let rec filter0 ?(acc = []) = function
    | [] -> reverse acc
    | x :: xs -> (filter0 [@tailcall]) ~acc:(if f x then x :: acc else acc) xs
  in
  filter0 xs

let fold ~init ~f xs =
  let rec fold0 ~acc = function
    | [] -> acc
    | x :: xs -> (fold0 [@tailcall]) ~acc:(f acc x) xs
  in
  fold0 ~acc:init xs

let append xs ys = fold ~init:ys ~f:(fun acc x -> x :: acc) (reverse xs)
let concat xs = fold ~init:[] ~f:(fun acc x -> append x acc) (reverse xs)
