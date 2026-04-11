#include "allergies.h"
#include <array>

namespace allergies {
static const std::array<std::string, 8> allergens = {
    "eggs",     "peanuts",   "shellfish", "strawberries",
    "tomatoes", "chocolate", "pollen",    "cats",
};

allergy_test::allergy_test(int score) {
  for (size_t i = 0; i < allergens.size(); i++) {
    if (score & (1 << i)) {
      allergies.emplace(allergens[i]);
    }
  }
}

bool allergy_test::is_allergic_to(const std::string &allergen) {
  return allergies.count(allergen) != 0;
}

const std::unordered_set<std::string> &allergy_test::get_allergies() {
  return allergies;
}
} // namespace allergies
