def is_armstrong_number(number: int):
    digits: list[int] = []

    n = number
    while n > 0:
        digits.append(n % 10)
        n //= 10

    n_digits = len(digits)

    return sum([d ** n_digits for d in digits]) == number
