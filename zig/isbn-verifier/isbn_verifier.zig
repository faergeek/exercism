const std = @import("std");

pub fn isValidIsbn10(s: []const u8) bool {
    var numbers: [10]u8 = undefined;

    var i: u8 = 0;
    for (s) |c| {
        var n: u8 = switch (c) {
            '0'...'9' => c - '0',
            'X' => if (i == 9) 10 else return false,
            '-' => continue,
            else => return false,
        };

        if (i >= 10) return false;

        numbers[i] = n;
        i += 1;
    }

    if (i != 10) return false;

    var sum: u64 = 0;
    i = 0;
    while (i < 10) : (i += 1) {
        sum += numbers[i] * (10 - i);
    }

    return sum % 11 == 0;
}
