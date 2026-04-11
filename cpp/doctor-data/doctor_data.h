#include <string>

using std::string;

namespace star_map {
enum class System {
  AlphaCentauri,
  BetaHydri,
  DeltaEridani,
  EpsilonEridani,
  Omicron2Eridani,
  Sol,
};
}

namespace heaven {
class Vessel {
public:
  string name;
  int generation;
  star_map::System current_system = star_map::System::Sol;
  int busters = 0;

  Vessel(string name, int generation);
  Vessel(string name, int generation, star_map::System system);

  Vessel replicate(string);
  void make_buster();
  bool shoot_buster();
};

string get_older_bob(Vessel, Vessel);
bool in_the_same_system(Vessel, Vessel);
} // namespace heaven
