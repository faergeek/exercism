open Base

let sort_chars str =
  String.to_list str |> List.sort ~compare:Char.compare |> String.of_char_list

let anagrams target candidates =
  let target = String.lowercase target in
  let target_sorted = sort_chars target in
  let is_anagram candidate =
    let candidate = String.lowercase candidate in
    String.(candidate <> target)
    &&
    let candidate_sorted = sort_chars candidate in
    String.(candidate_sorted = target_sorted)
  in
  List.filter candidates ~f:is_anagram
