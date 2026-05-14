#pragma once

#include <string>
#include <unordered_set>
namespace robot_name {

class robot {
private:
  static std::unordered_set<std::string> used_names;
  static std::string generate_unique_name();

  std::string m_name;

public:
  robot();
  std::string name() const;
  void reset();
};

} // namespace robot_name
