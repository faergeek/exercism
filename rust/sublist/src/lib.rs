#[derive(Debug, PartialEq, Eq)]
pub enum Comparison {
    Equal,
    Sublist,
    Superlist,
    Unequal,
}

fn compute_lps<T: PartialEq>(pattern: &[T]) -> Vec<usize> {
    let mut lps = Vec::with_capacity(pattern.len());
    lps.resize(pattern.len(), 0);

    let mut len = 0;
    let mut i = 1;

    while i < pattern.len() {
        if pattern[i] == pattern[len] {
            len += 1;
            lps[i] = len;
            i += 1;
        } else if len == 0 {
            lps[i] = 0;
            i += 1;
        } else {
            len = lps[len - 1];
        }
    }

    lps
}

fn includes<T: PartialEq>(list: &[T], pattern: &[T]) -> bool {
    if pattern.len() == 0 {
        return true;
    }

    let lps = compute_lps(pattern);
    let mut j = 0;
    let mut i = 0;

    while list.len() - i >= pattern.len() - j {
        if pattern[j] == list[i] {
            j += 1;
            i += 1;

            if j == pattern.len() {
                return true;
            }
        } else if j != 0 {
            j = lps[j - 1];
        } else {
            i += 1;
        }
    }

    false
}

pub fn sublist<T: PartialEq>(first_list: &[T], second_list: &[T]) -> Comparison {
    if first_list.len() > second_list.len() {
        if includes(first_list, second_list) {
            Comparison::Superlist
        } else {
            Comparison::Unequal
        }
    } else if second_list.len() > first_list.len() {
        if includes(second_list, first_list) {
            Comparison::Sublist
        } else {
            Comparison::Unequal
        }
    } else {
        for (i, first_val) in first_list.iter().enumerate() {
            if *first_val != second_list[i] {
                return Comparison::Unequal;
            }
        }

        Comparison::Equal
    }
}
