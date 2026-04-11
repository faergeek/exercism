let transform scores =
  scores
  |> List.concat_map (fun (score, chars) ->
         chars |> List.map (fun c -> (Char.lowercase_ascii c, score)))
  |> List.sort (fun (a, _) (b, _) -> Char.compare a b)
