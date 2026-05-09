def encode(numbers: list[int]):
    result: list[int] = []
    for number in reversed(numbers):
        result.append(number & 0x7F)

        bits = number >> 7
        while bits != 0:
            result.append(bits & 0x7F | 0x80)
            bits >>= 7

    result.reverse()
    return result


def decode(bytes_: list[int]):
    result: list[int] = []
    number = 0
    complete = True
    for byte in bytes_:
        number <<= 7
        number |= byte & 0x7F
        complete = not byte & 0x80

        if complete:
            result.append(number)
            number = 0

    if not complete:
        raise ValueError("incomplete sequence")

    return result
