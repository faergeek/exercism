open Base
open Poly
open Result.Monad_infix

let count_nucleotide s c =
  let validate = function
    | ('A' | 'C' | 'G' | 'T') as c -> Ok c
    | c -> Error c
  in
  validate c >>= fun ch ->
  String.to_list s
  |> List.fold_result ~init:0 ~f:(fun acc sc ->
         validate sc >>| fun sc -> acc + Bool.to_int (sc = ch))

let empty = Map.empty (module Char)

let count_nucleotides s =
  String.to_list s
  |> List.fold_result ~init:empty ~f:(fun acc c ->
         count_nucleotide s c >>= fun n -> Ok (Map.set acc ~key:c ~data:n))
