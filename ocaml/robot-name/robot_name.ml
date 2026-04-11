type robot = { mutable name : string }

module StringSet = Set.Make (String)

let used_names = ref StringSet.empty

let generate_random_name () =
  Random.self_init ();
  let char_in_range min max =
    Random.int_in_range ~min:(Char.code min) ~max:(Char.code max) |> Char.chr
  in
  let char () = char_in_range 'A' 'Z' and digit () = char_in_range '0' '9' in
  [ char (); char (); digit (); digit (); digit () ]
  |> List.to_seq |> String.of_seq

let rec generate_unique_name () =
  let new_name = generate_random_name () in
  if StringSet.mem new_name !used_names then
    (generate_unique_name [@tailcall]) ()
  else (
    used_names := StringSet.add new_name !used_names;
    new_name)

let new_robot () = { name = generate_unique_name () }
let name x = x.name
let reset x = x.name <- generate_unique_name ()
