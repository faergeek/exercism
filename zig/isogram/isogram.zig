const std = @import("std");

pub fn isIsogram(str: []const u8) bool {
    var chars = std.bit_set.IntegerBitSet(26).initEmpty();

    for (str) |ch| {
        var n = switch (ch) {
            'A'...'Z' => |c| c - 'A',
            'a'...'z' => |c| c - 'a',
            else => continue,
        };

        if (chars.isSet(n)) return false;

        chars.set(n);
    }

    return true;
}
