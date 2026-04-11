const std = @import("std");

pub fn isIsogram(str: []const u8) bool {
    var char_bits: u26 = 0;

    for (str) |ch| {
        var n: u5 = undefined;

        if (ch >= 'A' and ch <= 'Z')
            n = @intCast(u5, ch - 'A')
        else if (ch >= 'a' and ch <= 'z')
            n = @intCast(u5, ch - 'a')
        else
            continue;

        var one: u26 = 1;
        var bit: u26 = (one << n);

        if (char_bits & bit != 0) {
            return false;
        }

        char_bits |= bit;
    }

    return true;
}
