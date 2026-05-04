import math

COLOR_VALUES = {
    "black": 0,
    "brown": 1,
    "red": 2,
    "orange": 3,
    "yellow": 4,
    "green": 5,
    "blue": 6,
    "violet": 7,
    "grey": 8,
    "white": 9,
}

UNITS = ["ohms", "kiloohms", "megaohms", "gigaohms"]


def label(colors: list[str]):
    value = COLOR_VALUES[colors[0]] * 10 + COLOR_VALUES[colors[1]]
    zeroes = COLOR_VALUES[colors[2]]
    unit_index, zeroes = divmod(zeroes, 3)

    if unit_index > len(UNITS) - 1:
        zeroes += unit_index - (len(UNITS) - 1)
        unit_index = len(UNITS) - 1

    value *= 10**zeroes

    while value > 0 and value % 1000 == 0 and unit_index < len(UNITS) - 1:
        unit_index += 1
        zeroes += 3
        value /= 1000

    return f"{math.floor(value)} {UNITS[unit_index]}"
