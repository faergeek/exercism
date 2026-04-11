open Base

let sort_chars str =
  let array = String.to_array str in
  Array.sort array ~compare:Char.compare;
  String.of_array array

let anagrams target candidates =
  let open String in
  let target_lc = lowercase target in
  let target_lc_sorted = sort_chars target_lc in
  List.filter candidates ~f:(fun s ->
      lowercase s <> target_lc && sort_chars @@ lowercase s = target_lc_sorted)
