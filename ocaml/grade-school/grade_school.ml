open Base
module Int_map = Map.M (Int)

type school = string list Int_map.t

let empty_school = Map.empty (module Int)
let add student_name grade = Map.add_multi ~key:grade ~data:student_name
let grade grade school = Map.find school grade |> Option.value ~default:[]
let sorted = Map.map ~f:(List.sort ~compare:String.compare)
let roster school = school |> sorted |> Map.data |> List.concat
