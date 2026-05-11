def egg_count(display_value: int):
    return sum(1 for digit in bin(display_value) if digit == "1")
