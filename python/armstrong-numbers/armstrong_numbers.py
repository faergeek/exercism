def is_armstrong_number(number: int):
    digits: list[int] = []

    remainder = number
    while remainder > 0:
        digits.append(remainder % 10)
        remainder //= 10

    n_digits = len(digits)

    return sum([digit ** n_digits for digit in digits]) == number
