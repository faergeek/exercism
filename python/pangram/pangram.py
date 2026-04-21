ALPHABET = set(chr(codepoint) for codepoint in range(ord('a'), ord('z') + 1))

def is_pangram(sentence: str):
    return len(ALPHABET - set(sentence.lower())) == 0
