open Base

type allergen =
  | Eggs
  | Peanuts
  | Shellfish
  | Strawberries
  | Tomatoes
  | Chocolate
  | Pollen
  | Cats

let all_allergens =
  [ Eggs; Peanuts; Shellfish; Strawberries; Tomatoes; Chocolate; Pollen; Cats ]

let lshift_of_allergen allergen =
  fst (List.findi_exn all_allergens ~f:(fun _ x -> phys_equal x allergen))

let allergic_to score allergen =
  not (phys_equal (score land (1 lsl lshift_of_allergen allergen)) 0)

let allergies score =
  List.filteri all_allergens ~f:(fun i _ ->
      not (phys_equal (score land (1 lsl i)) 0))
