def rotate_char(char: str):
    return char if char.isnumeric() else chr(ord("z") - ord(char) + ord("a"))


def encode(plain_text: str):
    chars: list[str] = []
    for index, char in enumerate(char for char in plain_text.lower() if char.isalnum()):
        if index != 0 and index % 5 == 0:
            chars.append(" ")

        chars.append(rotate_char(char))

    return "".join(chars)


def decode(ciphered_text: str):
    return "".join(rotate_char(char) for char in ciphered_text if char != " ")
