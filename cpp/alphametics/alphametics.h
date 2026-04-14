#ifndef ALPHAMETICS_H
#define ALPHAMETICS_H

#include <optional>
#include <string>
#include <unordered_map>

namespace alphametics {

typedef std::unordered_map<char, int> solution;

std::optional<solution> solve(const std::string &input);

} // namespace alphametics

#endif
