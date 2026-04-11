let find array value =
  let rec find0 l h =
    if l > h then Result.Error "value not in array"
    else
      let m = l + ((h - l) / 2) in
      let x = Array.get array m in
      if x > value then (find0 [@tailcall]) l (m - 1)
      else if x < value then (find0 [@tailcall]) (m + 1) h
      else Result.Ok m
  in
  find0 0 (Array.length array - 1)