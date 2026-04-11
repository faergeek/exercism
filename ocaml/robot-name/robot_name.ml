type robot = { mutable name : string }

let int_in_range min max = min + Random.int (max - min + 1)
let char_in_range min max = Char.(int_in_range (code min) (code max) |> chr)

let generate_random_name () =
  Random.self_init ();
  let c () = char_in_range 'A' 'Z' and d () = char_in_range '0' '9' in
  [ c; c; d; d; d ] |> List.map (fun f -> f ()) |> List.to_seq |> String.of_seq

module StringSet = Set.Make (String)

let used_names = ref StringSet.empty

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
