const std = @import("std");

pub fn isPangram(str: []const u8) bool {
    var buffer: [1000]u8 = undefined;
    var fixed_buffer_allocator = std.heap.FixedBufferAllocator.init(&buffer);
    var str_chars = std.hash_map.AutoHashMap(u8, void).init(fixed_buffer_allocator.allocator());

    for (str) |c| {
        if (std.ascii.isAlphabetic(c)) {
            str_chars.put(std.ascii.toLower(c), undefined) catch unreachable;
        }
    }

    var c: u8 = 'a';
    while (c <= 'z') : (c += 1) {
        if (!str_chars.contains(c)) {
            return false;
        }
    }

    return true;
}
