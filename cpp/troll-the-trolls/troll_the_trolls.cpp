namespace hellmath {

enum class AccountStatus { troll, guest, user, mod };
enum class Action { read, write, remove };

bool display_post(AccountStatus poster_status, AccountStatus viewer_status) {
  switch (poster_status) {
  case AccountStatus::troll:
    return viewer_status == AccountStatus::troll;
  default:
    return true;
  }
}

bool permission_check(Action action, AccountStatus status) {
  switch (status) {
  case AccountStatus::guest:
    return action == Action::read;
  case AccountStatus::troll:
  case AccountStatus::user:
    return action == Action::read || action == Action::write;
  case AccountStatus::mod:
    return true;
  default:
    return false;
  }
}

bool valid_player_combination(AccountStatus player1, AccountStatus player2) {
  if (player1 == AccountStatus::guest || player2 == AccountStatus::guest) {
    return false;
  }

  switch (player1) {
  case AccountStatus::troll:
    return player2 == AccountStatus::troll;
  case AccountStatus::user:
  case AccountStatus::mod:
    return player2 != AccountStatus::troll;
  default:
    return false;
  }
}

bool has_priority(AccountStatus first, AccountStatus second) {
  return first > second;
}
} // namespace hellmath
