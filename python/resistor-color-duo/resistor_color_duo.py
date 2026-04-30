COLOR_CODES = {
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


def value(colors: list[str]):
    return int(COLOR_CODES[colors[0]]) * 10 + int(COLOR_CODES[colors[1]])
