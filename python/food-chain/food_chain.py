animals = ["fly", "spider", "bird", "cat", "dog", "goat", "cow", "horse"]

openings = [
    "It wriggled and jiggled and tickled inside her.",
    "How absurd to swallow a bird!",
    "Imagine that, to swallow a cat!",
    "What a hog, to swallow a dog!",
    "Just opened her throat and swallowed a goat!",
    "I don't know how she swallowed a cow!",
]

endings = [
    "She swallowed the cow to catch the goat.",
    "She swallowed the goat to catch the dog.",
    "She swallowed the dog to catch the cat.",
    "She swallowed the cat to catch the bird.",
    "She swallowed the bird to catch the spider that wriggled and jiggled and tickled inside her.",
    "She swallowed the spider to catch the fly.",
]


def recite(start_verse: int, end_verse: int):
    result: list[str] = []

    for verse in range(start_verse, end_verse + 1):
        if len(result) != 0:
            result.append("")

        result.append("I know an old lady who swallowed a " + animals[verse - 1] + ".")

        if verse > 7:
            result.append("She's dead, of course!")
        else:
            if verse > 1:
                result.append(openings[verse - 2])

            for index in range(len(endings) - (verse - 1), len(endings)):
                result.append(endings[index])

            result.append("I don't know why she swallowed the fly. Perhaps she'll die.")

    return result
