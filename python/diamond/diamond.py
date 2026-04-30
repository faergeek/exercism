def rows(letter: str):
    letter_index = ord(letter) - ord("A")
    size = letter_index * 2 + 1
    half_size = size // 2
    result: list[str] = []
    for index in range(size):
        char = chr(half_size - abs(index - half_size) + ord("A"))
        line = [" "] * size

        left = abs(index - half_size)
        line[left] = char

        right = size - left - 1
        line[right] = char

        result.append("".join(line))

    return result
