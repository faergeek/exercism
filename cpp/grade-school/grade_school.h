#pragma once

#include <map>
#include <set>
#include <string>
#include <vector>

namespace grade_school {

class school {
private:
  std::map<int, std::set<std::string>> m_roster;

public:
  void add(const std::string name, int grade);
  std::vector<std::string> grade(int grade) const;
  std::map<int, std::vector<std::string>> roster() const;
};

} // namespace grade_school
