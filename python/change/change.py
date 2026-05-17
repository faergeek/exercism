def find_fewest_coins(coins: list[int], target: int) -> list[int]:
    if target < 0:
        raise ValueError("target can't be negative")

    solutions: list[dict[int, int] | None] = [{}]
    reversed_coins = sorted((coin for coin in coins if coin <= target), reverse=True)
    for partial_target in range(1, target + 1):
        min_solution = None
        for coin in reversed_coins:
            if coin <= partial_target:
                partial_solution = solutions[partial_target - coin]

                if partial_solution is not None and (
                    min_solution is None
                    or sum(partial_solution.values()) + 1 < sum(min_solution.values())
                ):
                    min_solution = partial_solution.copy()

                    if coin in min_solution:
                        min_solution[coin] += 1
                    else:
                        min_solution[coin] = 1

        solutions.append(min_solution)

    solution = solutions[target]

    if solution is None:
        raise ValueError("can't make target with given coins")

    result: list[int] = []
    for coin in reversed_coins:
        if coin in solution:
            result.extend([coin] * solution[coin])

    result.sort()

    return result
