type planet =
  | Mercury
  | Venus
  | Earth
  | Mars
  | Jupiter
  | Saturn
  | Neptune
  | Uranus

let earth_year_seconds = 60.0 *. 60.0 *. 24.0 *. 365.25

let age_on planet age_in_seconds =
  Float.of_int age_in_seconds
  /. earth_year_seconds
  /.
  match planet with
  | Mercury -> 0.2408467
  | Venus -> 0.61519726
  | Earth -> 1.0
  | Mars -> 1.8808158
  | Jupiter -> 11.862615
  | Saturn -> 29.447498
  | Uranus -> 84.016846
  | Neptune -> 164.79132
