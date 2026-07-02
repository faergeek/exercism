class StatsItem:
    matches_won: int
    matches_drawn: int
    matches_lost: int

    def __init__(self, name: str, won: int, drawn: int, lost: int):
        self.name = name
        self.matches_won = won
        self.matches_drawn = drawn
        self.matches_lost = lost

    @property
    def matches_played(self):
        return self.matches_won + self.matches_drawn + self.matches_lost

    @property
    def points(self):
        return self.matches_won * 3 + self.matches_drawn

    def __lt__(self, other: "StatsItem"):
        return (
            self.name < other.name
            if self.points == other.points
            else self.points > other.points
        )


def tally(rows: list[str]):
    stats: dict[str, StatsItem] = {}

    for row in rows:
        parts = row.split(";")
        team1 = parts[0]
        team2 = parts[1]

        if team1 not in stats:
            stats[team1] = StatsItem(team1, 0, 0, 0)

        if team2 not in stats:
            stats[team2] = StatsItem(team2, 0, 0, 0)

        match parts[2]:
            case "win":
                stats[team1].matches_won += 1
                stats[team2].matches_lost += 1
            case "loss":
                stats[team1].matches_lost += 1
                stats[team2].matches_won += 1
            case "draw":
                stats[team1].matches_drawn += 1
                stats[team2].matches_drawn += 1
            case value:
                raise Exception("unexpected match result: " + value)

    result = [
        "Team                           | MP |  W |  D |  L |  P",
    ]

    result.extend(
        (
            "{name:<30} | {played:>2} | {won:>2} | {drawn:>2} | {lost:>2} | {points:>2}".format(
                name=team.name,
                played=team.matches_played,
                won=team.matches_won,
                drawn=team.matches_drawn,
                lost=team.matches_lost,
                points=team.points,
            )
            for team in sorted(stats.values())
        )
    )

    return result
