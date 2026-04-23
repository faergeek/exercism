from string import digits

valid_characters = set(digits).union({"-", "X"})


def is_valid(isbn: str):
    if any(char not in valid_characters for char in isbn):
        return False

    digits = [10 if digit == "X" else int(digit) for digit in isbn if digit != "-"]

    return (
        len(digits) == 10
        and all((digit != 10 or index == 9) for index, digit in enumerate(digits))
        and sum((digit * (10 - index)) for index, digit in enumerate(digits)) % 11 == 0
    )
