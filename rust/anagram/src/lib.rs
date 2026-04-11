use std::collections::HashSet;

fn into_sorted_chars(str: &str) -> Box<[char]> {
    let mut chars: Box<[char]> = str.chars().collect();
    chars.sort_unstable();

    chars
}

pub fn anagrams_for<'a>(word: &str, possible_anagrams: &'a [&str]) -> HashSet<&'a str> {
    let mut result = HashSet::new();

    let word_lc = word.to_lowercase();
    let word_chars = into_sorted_chars(&word_lc);

    for candidate in possible_anagrams {
        let candidate_lc = candidate.to_lowercase();

        if candidate_lc != word_lc {
            let chars: Box<[char]> = into_sorted_chars(&candidate_lc);

            if word_chars == chars {
                result.insert(*candidate);
            }
        }
    }

    result
}
