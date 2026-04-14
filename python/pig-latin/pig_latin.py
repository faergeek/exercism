vowels = {"a", "e", "i", "o", "u"}

def is_consonant(char: str):
    return char not in vowels

def translate_word(word: str):
    # Rule 1
    if word[0] in vowels or word[0:2] in {"xr", "yt"}:
        return f"{word}ay"

    # Rule 3
    qu_pos = word.find("qu")
    if qu_pos != -1 and all(is_consonant(char) for char in word[0:qu_pos]):
        split_at = qu_pos + 2
        return f"{word[split_at:]}{word[0:split_at]}ay"

    # Rule 4
    y_pos = word.find("y")
    if y_pos > 0 and all(is_consonant(char) for char in word[0:y_pos]):
        return f"{word[y_pos:]}{word[0:y_pos]}ay"

    # Rule 2
    split_at = 0
    while is_consonant(word[split_at]):
        split_at += 1

    return f"{word[split_at:]}{word[0:split_at]}ay"

def translate(text: str):
    return " ".join(translate_word(word) for word in text.split())
