import math


def rebase(input_base: int, digits: list[int], output_base: int):
    if input_base < 2:
        raise ValueError("input base must be >= 2")

    for digit in digits:
        if not 0 <= digit < input_base:
            raise ValueError("all digits must satisfy 0 <= d < input base")

    if output_base < 2:
        raise ValueError("output base must be >= 2")

    input = sum(
        digit * math.floor(math.pow(input_base, power))
        for power, digit in enumerate(reversed(digits))
    )

    if input == 0:
        return [0]

    result: list[int] = []
    while input > 0:
        input, remainder = divmod(input, output_base)
        result.insert(0, remainder)

    return result
