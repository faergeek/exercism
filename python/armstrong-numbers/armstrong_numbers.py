def is_armstrong_number(number: int):
    digits: list[int] = []

    remainder = number
    while remainder > 0:
        digits.append(remainder % 10)
        remainder //= 10

    n_digits = len(digits)

    return sum([d ** n_digits for d in digits]) == number
