#pragma once

#include <string>
#include <unordered_set>
namespace allergies {
class allergy_test {
public:
  allergy_test(int score);
  bool is_allergic_to(const std::string &allergen);
  const std::unordered_set<std::string> &get_allergies();

private:
  std::unordered_set<std::string> allergies;
};

} // namespace allergies
