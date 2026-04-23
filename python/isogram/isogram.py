from string import ascii_lowercase

letters = set(ascii_lowercase)


def is_isogram(string: str):
    letters_left = set(ascii_lowercase)

    for letter in string.lower():
        if letter in letters:
            if letter in letters_left:
                letters_left.remove(letter)
            else:
                return False

    return True
