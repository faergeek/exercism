actions = ["jump", "close your eyes", "double blink", "wink"]


def commands(binary_str: str):
    result = [
        actions[index] for index, digit in enumerate(binary_str[1:]) if digit == "1"
    ]

    if binary_str[0] == "0":
        result.reverse()

    return result
