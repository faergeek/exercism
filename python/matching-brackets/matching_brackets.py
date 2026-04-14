braces = {
    ")": "(",
    "]": "[",
    "}": "{",
}

def is_paired(input_string: str):
    stack: list[str] = []

    for character in input_string:
        if character in braces.values():
            stack.append(character)
        elif character in braces and (
            len(stack) == 0 or stack.pop() != braces[character]
        ):
            return False

    return len(stack) == 0
