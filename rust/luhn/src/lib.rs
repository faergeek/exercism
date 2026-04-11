/// Check a Luhn checksum.
pub fn is_valid(code: &str) -> bool {
    let mut digits = Vec::new();

    for &byte in code.as_bytes().iter().rev() {
        if byte == b' ' {
            continue;
        }

        if byte < b'0' || byte > b'9' {
            return false;
        }

        let mut d = (byte - b'0') as u64;

        if digits.len() % 2 == 1 {
            d = d * 2;

            if d > 9 {
                d -= 9;
            }
        }

        digits.push(d);
    }

    return digits.len() > 1 && (digits.iter().sum::<u64>()) % 10 == 0;
}
