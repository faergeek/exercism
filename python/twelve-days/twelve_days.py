numerals = [
    "first",
    "second",
    "third",
    "fourth",
    "fifth",
    "sixth",
    "seventh",
    "eighth",
    "ninth",
    "tenth",
    "eleventh",
    "twelfth",
]

parts = [
    "a Partridge in a Pear Tree.",
    "two Turtle Doves, ",
    "three French Hens, ",
    "four Calling Birds, ",
    "five Gold Rings, ",
    "six Geese-a-Laying, ",
    "seven Swans-a-Swimming, ",
    "eight Maids-a-Milking, ",
    "nine Ladies Dancing, ",
    "ten Lords-a-Leaping, ",
    "eleven Pipers Piping, ",
    "twelve Drummers Drumming, ",
]


def recite(start_verse: int, end_verse: int):
    result: list[str] = []

    for verse in range(start_verse, end_verse + 1):
        item = (
            f"On the {numerals[verse - 1]} day of Christmas my true love gave to me: "
        )

        for part_index in range(verse - 1, -1, -1):
            if verse != 1 and part_index == 0:
                item += "and "
            item += parts[part_index]

        result.append(item)

    return result
