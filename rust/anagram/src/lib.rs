use std::collections::HashSet;

fn into_sorted_chars(str: &str) -> Box<[char]> {
    let mut chars: Box<[char]> = str.chars().collect();
    chars.sort_unstable();

    chars
}

pub fn anagrams_for<'a>(word: &str, possible_anagrams: &'a [&str]) -> HashSet<&'a str> {
    let word_lc = word.to_lowercase();
    let word_chars = into_sorted_chars(&word_lc);

    possible_anagrams
        .iter()
        .filter(|candidate| {
            let candidate_lc = candidate.to_lowercase();

            candidate_lc != word_lc && word_chars == into_sorted_chars(&candidate_lc)
        })
        .copied()
        .collect()
}
