def calculate_factors(dividend: int):
    if dividend != 1:
        yield 1

    divisor = 2
    quotient, remainder = divmod(dividend, divisor)

    while quotient >= divisor:
        if remainder == 0:
            yield divisor

            if quotient != divisor:
                yield quotient

        divisor += 1
        quotient, remainder = divmod(dividend, divisor)


def classify(number: int):
    """A perfect number equals the sum of its positive divisors.

    :param number: int a positive integer
    :return: str the classification of the input integer
    """

    if number < 1:
        raise ValueError("Classification is only possible for positive integers.")

    aliquot_sum = sum(calculate_factors(number))

    if number < aliquot_sum:
        return "abundant"

    if number > aliquot_sum:
        return "deficient"

    return "perfect"
