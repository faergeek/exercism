#ifndef ALPHAMETICS_H
#define ALPHAMETICS_H

#include <optional>
#include <string>
#include <unordered_map>

namespace alphametics {

std::optional<std::unordered_map<char, int>> solve(const std::string &input);

} // namespace alphametics

#endif
