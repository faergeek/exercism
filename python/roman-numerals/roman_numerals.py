numerals = [
    ("M", 1000),
    ("D", 500),
    ("C", 100),
    ("L", 50),
    ("X", 10),
    ("V", 5),
    ("I", 1),
]


def roman(number: int):
    result: list[str] = []
    for index, (numeral, value) in enumerate(numerals):
        quotient, number = divmod(number, value)

        if quotient > 3:
            assert index > 0
            prev_numeral = numerals[index - 1][0]

            if len(result) > 0 and result[-1] == prev_numeral:
                assert index > 1
                result[-1] = numeral
                result.append(numerals[index - 2][0])
            else:
                result.append(numeral)
                result.append(prev_numeral)
        elif quotient != 0:
            result.extend([numeral] * quotient)

    return "".join(result)
