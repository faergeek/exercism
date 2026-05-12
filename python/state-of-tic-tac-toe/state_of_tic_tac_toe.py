win_states = [
    # horizontal
    ((0, 0), (0, 1), (0, 2)),
    ((1, 0), (1, 1), (1, 2)),
    ((2, 0), (2, 1), (2, 2)),
    # vertical
    ((0, 0), (1, 0), (2, 0)),
    ((0, 1), (1, 1), (2, 1)),
    ((0, 2), (1, 2), (2, 2)),
    # diagonal
    ((0, 0), (1, 1), (2, 2)),
    ((0, 2), (1, 1), (2, 0)),
]


def did_win(
    board: list[str],
    state: tuple[tuple[int, int], tuple[int, int], tuple[int, int]],
    player: str,
):
    return all(
        board[line_index][col_index] == player for line_index, col_index in state
    )


def gamestate(board: list[str]):
    x_count = sum(line.count("X") for line in board)
    o_count = sum(line.count("O") for line in board)

    turn_diff = x_count - o_count
    if turn_diff > 1:
        raise ValueError("Wrong turn order: X went twice")

    if turn_diff < 0:
        raise ValueError("Wrong turn order: O started")

    x_won = False
    o_won = False
    for state in win_states:
        line_index, col_index = state[0]
        cell = board[line_index][col_index]

        if cell == "X":
            x_won = x_won or did_win(board, state, "X")
        elif cell == "O":
            o_won = o_won or did_win(board, state, "O")

    if x_won and o_won:
        raise ValueError(
            "Impossible board: game should have ended after the game was won"
        )

    return "win" if x_won or o_won else "ongoing" if x_count + o_count < 9 else "draw"
