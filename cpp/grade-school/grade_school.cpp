#include "grade_school.h"

namespace grade_school {

void school::add(const std::string name, int grade) {
  m_roster[grade].insert(name);
}

std::vector<std::string> school::grade(int grade) const {
  auto found = m_roster.find(grade);

  return found == m_roster.end()
             ? std::vector<std::string>()
             : std::vector<std::string>(found->second.cbegin(),
                                        found->second.cend());
}

std::map<int, std::vector<std::string>> school::roster() const {
  std::map<int, std::vector<std::string>> result;

  for (auto pair : m_roster) {
    result.emplace(pair.first, std::vector<std::string>(pair.second.cbegin(),
                                                        pair.second.cend()));
  }

  return result;
}

} // namespace grade_school
