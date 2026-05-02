#pragma once

#include <cassert>
#include <stdexcept>
#include <utility>
namespace queen_attack {

typedef std::pair<int, int> position;

struct chess_board {
  position m_white;
  position m_black;

  chess_board(std::initializer_list<position> list);

  position white() const { return m_white; }
  position black() const { return m_black; }
  bool can_attack() const;
};

// TODO: add your solution here

} // namespace queen_attack
