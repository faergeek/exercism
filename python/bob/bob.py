def response(hey_bob: str):
    normalized = hey_bob.strip()

    if normalized == "":
        return "Fine. Be that way!"

    has_letters = False
    for letter in normalized:
        if "A" <= letter <= "Z":
            has_letters = True
            break

    is_a_question = normalized[-1] == "?"

    if has_letters and normalized == normalized.upper():
        if is_a_question:
            return "Calm down, I know what I'm doing!"

        return "Whoa, chill out!"

    if is_a_question:
        return "Sure."

    return "Whatever."
