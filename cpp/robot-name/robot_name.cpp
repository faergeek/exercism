#include "robot_name.h"

namespace robot_name {

std::unordered_set<std::string> robot::used_names;

std::string robot::generate_unique_name() {
  std::string result;

  do {
    result = "";
    result.push_back('A' + std::rand() % 26);
    result.push_back('A' + std::rand() % 26);
    result.push_back('0' + std::rand() % 10);
    result.push_back('0' + std::rand() % 10);
    result.push_back('0' + std::rand() % 10);
  } while (robot::used_names.find(result) != robot::used_names.end());

  robot::used_names.insert(result);

  return result;
}

robot::robot() { m_name = generate_unique_name(); }

std::string robot::name() const { return m_name; }

void robot::reset() { m_name = generate_unique_name(); }

} // namespace robot_name
