from enum import Enum

PREFIX = "What is "
SUFFIX = "?"


class Operand:
    value: int

    def __init__(self, value: int):
        self.value = value


class Operation:
    class Type(Enum):
        ADD = 1
        SUB = 2
        MUL = 3
        DIV = 4

    def __init__(self, type: Type):
        self.type = type


OPERATIONS = {
    "plus": Operation.Type.ADD,
    "minus": Operation.Type.SUB,
    "multiplied by": Operation.Type.MUL,
    "divided by": Operation.Type.DIV,
}


def answer(question: str):
    if not question.startswith(PREFIX) or not question.endswith(SUFFIX):
        raise ValueError("syntax error")

    tokens: list[Operand | Operation] = []
    start = len(PREFIX)
    question_len = len(question)
    while start < question_len:
        while question[start].isspace():
            start += 1

        if question[start] == "-" or question[start].isnumeric():
            operand_str = question[start]
            start += 1
            while question[start].isnumeric():
                operand_str += question[start]
                start += 1
            tokens.append(Operand(int(operand_str)))
        elif question[start] == SUFFIX:
            start += 1

            if start != question_len:
                raise ValueError("syntax error")
        else:
            operation = None
            for key in OPERATIONS:
                if question[start:].startswith(key):
                    operation = OPERATIONS[key]
                    start += len(key)
                    break

            if not operation:
                raise ValueError("unknown operation")

            tokens.append(Operation(operation))

    result = 0
    start = 0
    tokens_len = len(tokens)
    while start < tokens_len:
        token = tokens[start]

        if start == 0:
            if not isinstance(token, Operand):
                raise ValueError("syntax error")

            result = token.value
        else:
            if not isinstance(token, Operation):
                raise ValueError("syntax error")

            start += 1

            if start > tokens_len - 1:
                raise ValueError("syntax error")

            rhs = tokens[start]

            if not isinstance(rhs, Operand):
                raise ValueError("syntax error")

            match token.type:
                case Operation.Type.ADD:
                    result += rhs.value
                case Operation.Type.SUB:
                    result -= rhs.value
                case Operation.Type.MUL:
                    result *= rhs.value
                case Operation.Type.DIV:
                    result /= rhs.value

        start += 1

    return result
