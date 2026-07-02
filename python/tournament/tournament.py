from dataclasses import dataclass


@dataclass
class StatsItem:
    name: str
    won: int = 0
    drawn: int = 0
    lost: int = 0
    points: int = 0


def tally(rows: list[str]):
    stats: dict[str, StatsItem] = {}

    for row in rows:
        team1, team2, result = row.split(";")

        if team1 not in stats:
            stats[team1] = StatsItem(team1)

        if team2 not in stats:
            stats[team2] = StatsItem(team2)

        match result:
            case "win":
                stats[team1].won += 1
                stats[team2].lost += 1
                stats[team1].points += 3
            case "loss":
                stats[team1].lost += 1
                stats[team2].won += 1
                stats[team2].points += 3
            case "draw":
                stats[team1].drawn += 1
                stats[team1].points += 1
                stats[team2].drawn += 1
                stats[team2].points += 1
            case result:
                raise Exception("unexpected match result: " + result)

    result = ["Team                           | MP |  W |  D |  L |  P"]

    result.extend(
        (
            f"{team.name:<30} | {team.won + team.drawn + team.lost:>2} | {team.won:>2} | {team.drawn:>2} | {team.lost:>2} | {team.points:>2}"
            for team in sorted(stats.values(), key=lambda x: (-x.points, x.name))
        )
    )

    return result
