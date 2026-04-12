#include "power_of_troy.h"
#include <utility>

namespace troy {

void give_new_artifact(human &human, const std::string &artifact_name) {
  human.possession = std::make_unique<artifact>(artifact_name);
}

void exchange_artifacts(std::unique_ptr<artifact> &a,
                        std::unique_ptr<artifact> &b) {
  auto &temp = a;
  b = std::move(a);
  a = std::move(temp);
}

void manifest_power(human &human, const std::string &power_name) {
  human.own_power = std::make_unique<power>(power_name);
}

void use_power(human &caster, human &target) {
  target.influenced_by = caster.own_power;
}

long power_intensity(const human &caster) {
  return caster.own_power.use_count();
}

} // namespace troy
