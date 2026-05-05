COLOR_TO_VALUE = {
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

UNITS = ["ohms", "kiloohms", "megaohms"]

COLOR_TO_TOLERANCE = {
    "grey": "0.05%",
    "violet": "0.1%",
    "blue": "0.25%",
    "green": "0.5%",
    "brown": "1%",
    "red": "2%",
    "gold": "5%",
    "silver": "10%",
}


def resistor_label(colors: list[str]):
    if len(colors) == 1:
        return "0 ohms"

    value: float
    zeroes: int
    tolerance: str

    if len(colors) == 4:
        value = COLOR_TO_VALUE[colors[0]] * 10 + COLOR_TO_VALUE[colors[1]]
        zeroes = COLOR_TO_VALUE[colors[2]]
        tolerance = COLOR_TO_TOLERANCE[colors[3]]
    elif len(colors) == 5:
        value = (
            COLOR_TO_VALUE[colors[0]] * 100
            + COLOR_TO_VALUE[colors[1]] * 10
            + COLOR_TO_VALUE[colors[2]]
        )
        zeroes = COLOR_TO_VALUE[colors[3]]
        tolerance = COLOR_TO_TOLERANCE[colors[4]]
    else:
        raise ValueError("invalid band count")

    while value != 0 and value % 10 == 0:
        value /= 10
        zeroes += 1

    unit_index = 0
    while zeroes >= 3 and unit_index < len(UNITS) - 1:
        zeroes -= 3
        unit_index += 1

    value *= 10**zeroes

    while value > 1000 and unit_index < len(UNITS) - 1:
        value /= 1000
        unit_index += 1

    return f"{'%g' % value} {UNITS[unit_index]} ±{tolerance}"
