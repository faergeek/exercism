const std = @import("std");
const mem = std.mem;

pub const Signal = enum {
    wink,
    double_blink,
    close_your_eyes,
    jump,
};

pub fn calculateHandshake(allocator: mem.Allocator, number: isize) mem.Allocator.Error![]const Signal {
    var len: u8 = 0;
    const buffer = try allocator.alloc(Signal, 4);
    defer allocator.free(buffer);

    if (number & 0b00001 != 0) {
        buffer[len] = .wink;
        len += 1;
    }

    if (number & 0b00010 != 0) {
        buffer[len] = .double_blink;
        len += 1;
    }

    if (number & 0b00100 != 0) {
        buffer[len] = .close_your_eyes;
        len += 1;
    }

    if (number & 0b01000 != 0) {
        buffer[len] = .jump;
        len += 1;
    }

    const result = try allocator.alloc(Signal, len);

    var i: @TypeOf(len) = 0;
    if (number & 0b10000 == 0) {
        while (i < len) : (i += 1) {
            result[i] = buffer[i];
        }
    } else {
        while (i < len) : (i += 1) {
            result[i] = buffer[len - 1 - i];
        }
    }

    return result;
}
