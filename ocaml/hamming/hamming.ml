type nucleotide = A | C | G | T

let hamming_distance l r =
  match (List.length l, List.length r) with
  | 0, r_len when r_len != 0 -> Error "left strand must not be empty"
  | l_len, 0 when l_len != 0 -> Error "right strand must not be empty"
  | l_len, r_len when l_len != r_len ->
      Error "left and right strands must be of equal length"
  | _ ->
      let l_seq = List.to_seq l and r_seq = List.to_seq r in
      let zipped_seq = Seq.zip l_seq r_seq in
      let zipped_list = List.of_seq zipped_seq in
      let rec f = function
        | [] -> 0
        | (a, b) :: t ->
            let cur = if a == b then 0 else 1 in
            cur + f t
      in
      Result.Ok (f zipped_list)
