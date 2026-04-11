def is_a_triangle(sides: list[int]):
    return all(
        0 < length <= sides[(index + 1) % 3] + sides[(index + 2) % 3]
        for index, length in enumerate(sides)
    )

def equilateral(sides: list[int]):
    return is_a_triangle(sides) and sides[0] == sides[1] and sides[1] == sides[2]

def isosceles(sides: list[int]):
    return (
        equilateral(sides) or
        is_a_triangle(sides) and (
            sides[0] == sides[1] or
            sides[1] == sides[2] or
            sides[2] == sides[0]
        )
    )

def scalene(sides: list[int]):
    return not isosceles(sides) and is_a_triangle(sides)
