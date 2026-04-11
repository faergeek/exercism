open Base

let make_change ~target ~coins =
  if target < 0 then Error "target can't be negative"
  else
    let rec make_change0 target ?(results = []) = function
      | [] ->
          results |> List.filter_opt
          |> List.sort ~compare:(fun a b ->
                 Int.compare (List.length a) (List.length b))
          |> List.hd
          |> Result.of_option ~error:"can't make target with given coins"
      | coins ->
          let rec compute_change target coins result =
            if target = 0 then Some result
            else
              match coins with
              | [] -> None
              | coin :: coins_left ->
                  if target >= coin then
                    match
                      compute_change (target - coin) coins (coin :: result)
                    with
                    | None ->
                        compute_change (target - coin) coins_left
                          (coin :: result)
                    | Some greedy_result -> Some greedy_result
                  else compute_change target coins_left result
          in
          make_change0 target (List.tl_exn coins)
            ~results:(compute_change target coins [] :: results)
    in
    coins |> List.sort ~compare:Int.compare |> List.rev |> make_change0 target
