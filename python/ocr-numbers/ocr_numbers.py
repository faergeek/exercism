numbers_ascii = [
    [" _ ", "| |", "|_|", "   "],
    ["   ", "  |", "  |", "   "],
    [" _ ", " _|", "|_ ", "   "],
    [" _ ", " _|", " _|", "   "],
    ["   ", "|_|", "  |", "   "],
    [" _ ", "|_ ", " _|", "   "],
    [" _ ", "|_ ", "|_|", "   "],
    [" _ ", "  |", "  |", "   "],
    [" _ ", "|_|", "|_|", "   "],
    [" _ ", "|_|", " _|", "   "],
]


def convert(input_grid: list[str]):
    if len(input_grid) % 4 != 0:
        raise ValueError("Number of input lines is not a multiple of four")

    for input_line in input_grid:
        if len(input_line) % 3 != 0:
            raise ValueError("Number of input columns is not a multiple of three")

    result = ""
    for start_row in range(0, len(input_grid), 4):
        line: list[str] = []

        for start_col in range(0, len(input_grid[0]), 3):
            character = "?"

            for index, number in enumerate(numbers_ascii):
                matches = True
                for row in range(0, 4):
                    if (
                        input_grid[start_row + row][start_col : start_col + 3]
                        != number[row]
                    ):
                        matches = False
                        break

                if matches:
                    character = str(index)
                    break

            line.append(character)

        if result:
            result += ","

        result += "".join(line)

    return result
