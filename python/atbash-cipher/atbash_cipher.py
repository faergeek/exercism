from string import ascii_lowercase

ENCODING = str.maketrans(ascii_lowercase, ascii_lowercase[::-1])


def encode(plain_text: str):
    chars = [char for char in plain_text.lower() if char.isalnum()]

    return " ".join(
        "".join(chars[offset : offset + 5]).translate(ENCODING)
        for offset in range(0, len(chars), 5)
    )


def decode(ciphered_text: str):
    return "".join(char for char in ciphered_text if char != " ").translate(ENCODING)
