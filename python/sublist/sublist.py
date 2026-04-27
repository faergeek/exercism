"""
This exercise stub and the test suite contain several enumerated constants.

Enumerated constants can be done with a NAME assigned to an arbitrary,
but unique value. An integer is traditionally used because it’s memory
efficient.
It is a common practice to export both constants and functions that work with
those constants (ex. the constants in the os, subprocess and re modules).

You can learn more here: https://en.wikipedia.org/wiki/Enumerated_type
"""

# Possible sublist categories.
# Change the values as you see fit.
SUBLIST = "sublist"
SUPERLIST = "superlist"
EQUAL = "equal"
UNEQUAL = "unequal"


def index_of[Item](super: list[Item], sub: list[Item]):
    result = -1
    for super_index, _ in enumerate(super):
        result = super_index

        for sub_index, sub_char in enumerate(sub):
            if super[super_index + sub_index] != sub_char:
                result = -1
                break

        if result != -1:
            return True

    return result


def sublist[Item](list_one: list[Item], list_two: list[Item]):
    if len(list_one) == len(list_two):
        return (
            EQUAL
            if all(list_a == list_b for list_a, list_b in zip(list_one, list_two))
            else UNEQUAL
        )

    if len(list_one) > len(list_two):
        if index_of(list_one, list_two) != -1:
            return SUPERLIST
    else:
        if index_of(list_two, list_one) != -1:
            return SUBLIST

    return UNEQUAL
