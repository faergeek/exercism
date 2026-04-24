def rotate_char(char: str, key: int):
    if not char.isalpha():
        return char

    offset = ord("a" if char.islower() else "A")
    return chr((ord(char) - offset + key) % 26 + offset)


def rotate(text: str, key: int):
    return "".join(rotate_char(char, key) for char in text)
