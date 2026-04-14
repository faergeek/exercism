braces = {
    ")": "(",
    "]": "[",
    "}": "{",
}

def is_paired(input_string: str):
    stack: list[str] = []

    for c in input_string:
        if c in braces.values():
            stack.append(c)
        elif c in braces and (
            len(stack) == 0 or stack.pop() != braces[c]
        ):
            return False

    return len(stack) == 0
