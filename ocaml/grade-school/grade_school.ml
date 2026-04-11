open Base
module Int_map = Map.M (Int)

type school = string list Int_map.t

let empty_school = Map.empty (module Int)

let add student_name grade school =
  Map.update school grade ~f:(function
    | Some x -> student_name :: x
    | None -> [ student_name ])

let grade grade school = Map.find school grade |> Option.value ~default:[]
let sorted = Map.map ~f:(List.sort ~compare:String.compare)

let roster school =
  Map.keys school
  |> List.sort ~compare:Int.compare
  |> List.concat_map ~f:(fun grade ->
         Map.find_exn school grade |> List.sort ~compare:String.compare)
