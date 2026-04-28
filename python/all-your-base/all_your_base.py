def rebase(input_base: int, digits: list[int], output_base: int):
    if input_base < 2:
        raise ValueError("input base must be >= 2")

    for digit in digits:
        if not 0 <= digit < input_base:
            raise ValueError("all digits must satisfy 0 <= d < input base")

    if output_base < 2:
        raise ValueError("output base must be >= 2")

    input_number = sum(
        digit * input_base**power for power, digit in enumerate(reversed(digits))
    )

    if input_number == 0:
        return [0]

    result: list[int] = []
    while input_number > 0:
        input_number, remainder = divmod(input_number, output_base)
        result.insert(0, remainder)

    return result
