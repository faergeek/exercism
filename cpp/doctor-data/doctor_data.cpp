#include "doctor_data.h"

namespace heaven {
Vessel::Vessel(string n, int g) {
  name = n;
  generation = g;
}

Vessel::Vessel(string n, int g, star_map::System system) {
  name = n;
  generation = g;
  current_system = system;
}

Vessel Vessel::replicate(string n) {
  return Vessel(n, generation + 1, current_system);
}

void Vessel::make_buster() { busters++; }
bool Vessel::shoot_buster() { return busters-- != 0; }

string get_older_bob(Vessel first, Vessel second) {
  return first.generation < second.generation ? first.name : second.name;
}

bool in_the_same_system(Vessel first, Vessel second) {
  return first.current_system == second.current_system;
}
} // namespace heaven
