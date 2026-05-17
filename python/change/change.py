def find_fewest_coins0(
    coins: list[int],
    target: int,
    candidate: dict[int, int],
    best_candidate: dict[int, int] | None = None,
) -> dict[int, int] | None:
    if target == 0:
        return best_candidate

    if best_candidate and sum(candidate.values()) > sum(best_candidate.values()):
        return best_candidate

    for index, coin in enumerate(coins):
        if coin > target:
            continue

        if coin not in candidate:
            candidate[coin] = 0

        candidate[coin] += 1

        if coin < target:
            nested_candidate = find_fewest_coins0(
                coins[index:], target - coin, candidate, best_candidate
            )

            if nested_candidate and (
                not best_candidate
                or sum(nested_candidate.values()) < sum(best_candidate.values())
            ):
                best_candidate = nested_candidate.copy()
        else:
            if not best_candidate or sum(candidate.values()) < sum(
                best_candidate.values()
            ):
                best_candidate = candidate.copy()

        candidate[coin] -= 1

    return best_candidate


def find_fewest_coins(coins: list[int], target: int) -> list[int]:
    if target < 0:
        raise ValueError("target can't be negative")

    if target == 0:
        return []

    reversed_coins = sorted((coin for coin in coins if coin <= target), reverse=True)
    solution = find_fewest_coins0(reversed_coins, target, {})

    if not solution:
        raise ValueError("can't make target with given coins")

    result: list[int] = []
    for coin in reversed_coins:
        if coin in solution:
            result.extend([coin] * solution[coin])

    result.sort()

    return result
