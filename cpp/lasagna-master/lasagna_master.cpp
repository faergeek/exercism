#include "lasagna_master.h"

namespace lasagna_master {

int preparationTime(const std::vector<std::string> layers, int averagePreparationTime) {
  return layers.size() * averagePreparationTime;
}

amount quantities(const std::vector<std::string> layers) {
  amount result{0, 0.0};

  for (auto &layer : layers) {
    if (layer == "noodles") {
      result.noodles += 50;
    } else if (layer == "sauce") {
      result.sauce += 0.2;
    }
  }

  return result;
}

void addSecretIngredient(std::vector<std::string> &ingredients, const std::vector<std::string> &friendsIngredients) {
  addSecretIngredient(ingredients, friendsIngredients[friendsIngredients.size() - 1]);
}

void addSecretIngredient(std::vector<std::string> &ingredients, const std::string &secretIngredient) {
  ingredients.back() = secretIngredient;
}

std::vector<double> scaleRecipe(const std::vector<double> &quantities, int numberOfPortions) {
  std::vector<double> result(quantities.size());

  for (size_t i = 0; i < quantities.size(); i++) {
    result[i] = quantities[i] / 2 * numberOfPortions;
  }

  return result;
}

}  // namespace lasagna_master
