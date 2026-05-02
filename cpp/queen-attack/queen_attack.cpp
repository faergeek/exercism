#include "queen_attack.h"

namespace queen_attack {

chess_board::chess_board(std::initializer_list<position> list) {
  auto it = list.begin();
  m_white = *it;
  it++;
  m_black = *it;
  it++;

  if (it != list.end() || m_white == m_black || m_white.first < 0 ||
      m_white.first > 7 || m_white.second < 0 || m_white.second > 7 ||
      m_black.first < 0 || m_black.first > 7 || m_black.second < 0 ||
      m_black.second > 7) {
    throw std::domain_error("Invalid positions");
  }
}

bool chess_board::can_attack() const {
  return m_white.first == m_black.first || m_white.second == m_black.second ||
         abs(m_white.first - m_black.first) ==
             abs(m_white.second - m_black.second);
}

} // namespace queen_attack
