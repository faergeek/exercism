use std::collections::HashSet;

pub fn is_pangram(sentence: &str) -> bool {
    sentence
        .chars()
        .map(|c| c.to_ascii_lowercase())
        .filter(|c| c >= &'a' && c <= &'z')
        .collect::<HashSet<_>>()
        .len()
        == 26
}
