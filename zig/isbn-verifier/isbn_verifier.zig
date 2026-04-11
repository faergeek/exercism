pub fn isValidIsbn10(s: []const u8) bool {
    var sum: u16 = 0;

    var i: u8 = 0;
    for (s) |c| {
        var digit: u8 = switch (c) {
            '0'...'9' => c - '0',
            'X' => if (i == 9) 10 else return false,
            '-' => continue,
            else => return false,
        };

        sum += (10 - i) * digit;
        i += 1;
    }

    return i == 10 and sum % 11 == 0;
}
