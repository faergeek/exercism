#include <string>
#define EXERCISM_RUN_ALL_TESTS

using std::string;

namespace log_line {
static string log_level_suffix = "]: ";

string message(string input) {
  size_t index = input.find(log_level_suffix);

  return input.substr(index + log_level_suffix.length());
}

string log_level(string input) {
  return input.substr(1, input.find(log_level_suffix) - 1);
}

string reformat(string input) {
  string msg = message(input);
  string level = log_level(input);

  return msg + " (" + level + ")";
}
} // namespace log_line
