NUMERAL_WORD = [
    "No",
    "One",
    "Two",
    "Three",
    "Four",
    "Five",
    "Six",
    "Seven",
    "Eight",
    "Nine",
    "Ten",
]


def bottle_plural(index: int):
    return "bottle" if index == 1 else "bottles"


def get_part(index: int):
    word = NUMERAL_WORD[index]

    return [
        f"{word} green {bottle_plural(index)} hanging on the wall,",
        f"{word} green {bottle_plural(index)} hanging on the wall,",
        "And if one green bottle should accidentally fall,",
        f"There'll be {NUMERAL_WORD[index - 1].lower()} green {bottle_plural(index - 1)} hanging on the wall.",
    ]


def recite(start: int, take: int = 1):
    result: list[str] = []

    for index in range(start, start - take, -1):
        if result:
            result.append("")

        result.extend(get_part(index))

    return result
