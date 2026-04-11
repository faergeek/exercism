/// Check a Luhn checksum.
pub fn is_valid(code: &str) -> bool {
    code.as_bytes()
        .iter()
        .filter(|byte| !byte.is_ascii_whitespace())
        .try_rfold((0, 0), |(sum, count), &byte| {
            (byte as char).to_digit(10).map(|mut digit| {
                if count % 2 == 1 {
                    digit = digit * 2;

                    if digit > 9 {
                        digit -= 9;
                    }
                }

                (sum + digit, count + 1)
            })
        })
        .map_or(false, |(sum, count)| count > 1 && sum % 10 == 0)
}
