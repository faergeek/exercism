from dataclasses import dataclass
from enum import Enum

PREFIX = "What is "
SUFFIX = "?"


@dataclass
class Operand:
    value: int


@dataclass
class Operation:
    class Type(Enum):
        ADD = 1
        SUB = 2
        MUL = 3
        DIV = 4

    type: Type


OPERATIONS = {
    "plus": Operation.Type.ADD,
    "minus": Operation.Type.SUB,
    "multiplied by": Operation.Type.MUL,
    "divided by": Operation.Type.DIV,
}


def tokenize(input: str):
    if not input.startswith(PREFIX) or not input.endswith(SUFFIX):
        raise ValueError("syntax error")

    tokens: list[Operand | Operation] = []
    start = len(PREFIX)
    question_len = len(input)
    while start < question_len:
        while input[start].isspace():
            start += 1

        if input[start] == "-" or input[start].isnumeric():
            operand_str = input[start]
            start += 1
            while input[start].isnumeric():
                operand_str += input[start]
                start += 1
            tokens.append(Operand(int(operand_str)))
        elif input[start] == SUFFIX:
            start += 1

            if start != question_len:
                raise ValueError("syntax error")
        else:
            operation = None
            for key, value in OPERATIONS.items():
                if input[start:].startswith(key):
                    operation = value
                    start += len(key)
                    break

            if not operation:
                raise ValueError("unknown operation")

            tokens.append(Operation(operation))

    return tokens


def evaluate(tokens: list[Operand | Operation]):
    if not isinstance(tokens[0], Operand):
        raise ValueError("syntax error")

    result = tokens[0].value
    start = 1
    tokens_len = len(tokens)
    while start < tokens_len:
        operation = tokens[start]

        if not isinstance(operation, Operation):
            raise ValueError("syntax error")

        start += 1

        if start > tokens_len - 1:
            raise ValueError("syntax error")

        rhs = tokens[start]

        if not isinstance(rhs, Operand):
            raise ValueError("syntax error")

        match operation.type:
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


def answer(question: str):
    return evaluate(tokenize(question))
