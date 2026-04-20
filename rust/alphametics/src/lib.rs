use std::collections::{HashMap, HashSet};

const ALPHABET_SIZE: usize = 'Z' as usize - 'A' as usize;

struct Puzzle {
    letters: Vec<usize>,
    matrix: Vec<usize>,
    max_term_len: usize,
    term_lengths: Vec<usize>,
}

impl Puzzle {
    fn new(input: &str) -> Puzzle {
        let mut max_term_len = 0;
        let mut term_count = 0;
        {
            let mut cur_term_len = 0;
            for c in input.chars().rev() {
                if c.is_ascii_alphabetic() {
                    if cur_term_len == 0 {
                        term_count += 1;
                    }

                    cur_term_len += 1;
                } else {
                    if cur_term_len > max_term_len {
                        max_term_len = cur_term_len;
                    }

                    cur_term_len = 0;
                }
            }

            if cur_term_len > max_term_len {
                max_term_len = cur_term_len;
            }
        }

        let mut matrix = vec![0; term_count * max_term_len];
        let mut term_lengths = vec![0; term_count];

        let mut letter_indices_set: HashSet<usize> = HashSet::new();

        let mut term_index: usize = 0;
        let mut chars = input.chars().rev();
        loop {
            let mut it = chars.next();

            loop {
                match it {
                    None => break,
                    Some(c) => {
                        if c.is_whitespace() {
                            it = chars.next();
                        } else {
                            break;
                        }
                    }
                }
            }

            match it {
                None => break,
                Some('=') => {
                    it = chars.next();

                    match it {
                        Some('=') => (),
                        Some(c) => {
                            panic!("Expected a second '=' after '=', got {c}")
                        }
                        None => {
                            panic!("Unexpected end of input, expected a second '=' after '='")
                        }
                    }
                }
                Some('+') => (),
                Some(mut c) => {
                    if c.is_ascii_alphabetic() {
                        let mut term_len: usize = 0;
                        let mut column: usize = 0;
                        loop {
                            let letter_index = c as usize - 'A' as usize;
                            matrix[column * term_count + term_index] = letter_index;
                            letter_indices_set.insert(letter_index);

                            term_len += 1;
                            column += 1;
                            it = chars.next();

                            match it {
                                None => break,
                                Some(c2) => {
                                    if !c2.is_ascii_alphabetic() {
                                        break;
                                    }

                                    c = c2
                                }
                            }
                        }

                        term_lengths[term_index] = term_len;
                        term_index += 1;
                    } else {
                        panic!("Unexpected character {c}")
                    }
                }
            }
        }

        Self {
            letters: letter_indices_set.into_iter().collect(),
            matrix,
            max_term_len,
            term_lengths,
        }
    }

    fn is_valid(&self, permutation: &[isize]) -> bool {
        let mut sum = 0;
        let mut cell_index = 0;
        for column in 0..self.max_term_len {
            for (term_index, term_len) in self.term_lengths.iter().enumerate() {
                if column > term_len - 1 {
                    cell_index += 1;
                    continue;
                }

                let index = self.matrix[cell_index];
                let digit = permutation[index];

                if digit == 0 && column == term_len - 1 {
                    return false;
                }

                if term_index == 0 {
                    sum -= digit;
                } else {
                    sum += digit;
                }

                cell_index += 1;
            }

            if sum % 10 != 0 {
                break;
            }

            sum /= 10;
        }

        sum == 0
    }

    // Steinhaus–Johnson–Trotter algorithm with Even's speedup
    // https://en.wikipedia.org/wiki/Steinhaus%E2%80%93Johnson%E2%80%93Trotter_algorithm#Even's_speedup
    fn permute(
        &self,
        permutation: &mut [isize],
        directions: &mut [isize],
        indices: &mut [usize],
    ) -> bool {
        let mut max_i: isize = -1;
        let mut max_n: isize = -1;
        for i in 0..indices.len() {
            if directions[i] != 0 && indices[i] as isize > max_n {
                max_i = i as isize;
                max_n = indices[i] as isize;
            }
        }

        if max_i == -1 {
            return false;
        }

        let src_i = max_i as usize;

        let direction = directions[src_i];
        let dst_i = (src_i as isize + direction) as usize;

        permutation.swap(indices[src_i], indices[dst_i]);
        indices.swap(src_i, dst_i);
        directions.swap(src_i, dst_i);

        if dst_i == 0
            || dst_i == self.letters.len() - 1
            || indices[(dst_i as isize + direction) as usize] > indices[dst_i]
        {
            directions[dst_i] = 0;
        }

        for i in 0..self.letters.len() {
            if indices[i] > max_n as usize {
                if i > dst_i {
                    directions[i] = -1
                } else {
                    directions[i] = 1
                }
            }
        }

        true
    }

    fn search(
        &self,
        solution: &mut Vec<isize>,
        next_digit_base: isize,
        letter_index: usize,
    ) -> bool {
        if letter_index < self.letters.len() {
            for next_digit in next_digit_base..10 {
                solution[self.letters[letter_index]] = next_digit;

                if self.search(solution, next_digit + 1, letter_index + 1) {
                    return true;
                }
            }

            return false;
        }

        let mut permutation = solution.to_vec();
        let mut indices: Vec<usize> = vec![0; self.letters.len()];
        let mut j = 0;
        for i in 0..permutation.len() {
            if permutation[i] >= 0 {
                indices[j] = i;
                j += 1;
            }
        }

        let mut directions = vec![-1; self.letters.len()];
        directions[0] = 0;

        let mut found: bool;
        loop {
            found = self.is_valid(&permutation);

            if !found && !self.permute(&mut permutation, &mut directions, &mut indices) {
                break;
            }

            if found {
                break;
            }
        }

        if found {
            *solution = permutation;
        }

        found
    }

    fn solve(&self) -> Option<HashMap<char, u8>> {
        let mut solution: Vec<isize> = vec![-255; ALPHABET_SIZE];

        if !self.search(&mut solution, 0, 0) {
            return None;
        }

        let mut result: HashMap<char, u8> = HashMap::new();
        for letter in self.letters.iter() {
            result.insert(
                ('A' as usize + letter) as u8 as char,
                solution[*letter] as u8,
            );
        }

        Some(result)
    }
}

pub fn solve(input: &str) -> Option<HashMap<char, u8>> {
    Puzzle::new(input).solve()
}
