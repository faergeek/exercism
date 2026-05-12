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


def gamestate(board: list[str]):
    x_count = 0
    o_count = 0
    for line in board:
        for cell in line:
            if cell == "X":
                x_count += 1
            elif cell == "O":
                o_count += 1

    turn_diff = x_count - o_count
    if turn_diff > 1:
        raise ValueError("Wrong turn order: X went twice")

    if turn_diff < 0:
        raise ValueError("Wrong turn order: O started")

    x_won = False
    o_won = False
    for state in win_states:
        cell = board[state[0][0]][state[0][1]]
        if cell == " ":
            continue

        won = True
        for line_index, col_index in state:
            if board[line_index][col_index] != cell:
                won = False
                break

        if won:
            if cell == "X":
                x_won = True
            else:
                o_won = True

    if x_won and o_won:
        raise ValueError(
            "Impossible board: game should have ended after the game was won"
        )

    if x_won or o_won:
        return "win"

    draw = True
    for line in board:
        for cell in line:
            if cell == " ":
                draw = False
                break

    if draw:
        return "draw"

    return "ongoing"
