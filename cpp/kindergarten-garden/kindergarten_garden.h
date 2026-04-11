#pragma once

#include <array>
#include <string>
namespace kindergarten_garden {
enum class Plants {
  clover,
  grass,
  violets,
  radishes,
};

std::array<kindergarten_garden::Plants, 4> plants(std::string diagram,
                                                  std::string student);
} // namespace kindergarten_garden
