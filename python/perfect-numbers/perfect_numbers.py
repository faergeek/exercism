def classify(number: int):
    """A perfect number equals the sum of its positive divisors.

    :param number: int a positive integer
    :return: str the classification of the input integer
    """

    if number < 1:
        raise ValueError("Classification is only possible for positive integers.")

    aliquot_sum = 0 if number == 1 else 1
    divisor = 2
    quotient, remainder = divmod(number, divisor)
    while quotient >= divisor:
        if remainder == 0:
            aliquot_sum += divisor

            if quotient != divisor:
                aliquot_sum += quotient
            if aliquot_sum > number:
                return "abundant"

        divisor += 1
        quotient, remainder = divmod(number, divisor)

    if number > aliquot_sum:
        return "deficient"

    return "perfect"
