def annotate(garden: list[str]):
    result: list[str] = []

    if len(garden) == 0:
        return result

    line_count = len(garden)
    line_len = len(garden[0])
    for i in range(line_count):
        if len(garden[i]) != line_len:
            raise ValueError("The board is invalid with current input.")

        line = ""

        for j in range(line_len):
            match garden[i][j]:
                case " ":
                    count = sum(
                        garden[x][y] == "*"
                        for x in range(i - 1, i + 2)
                        if 0 <= x < line_count
                        for y in range(j - 1, j + 2)
                        if 0 <= y < line_len
                    )

                    line += " " if count == 0 else str(count)
                case "*":
                    line += garden[i][j]
                case _:
                    raise ValueError("The board is invalid with current input.")

        result.append(line)

    return result
