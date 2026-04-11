const std = @import("std");

pub fn primes(buffer: []u32, limit: u32) []u32 {
    var gpa = std.heap.GeneralPurposeAllocator(.{}){};
    const allocator = gpa.allocator();
    defer _ = gpa.deinit();

    var size = if (limit == 0) 0 else limit - 1;
    var numbers = allocator.alloc(?u32, size) catch unreachable;
    defer allocator.free(numbers);

    var i: u32 = 0;
    while (i < size) : (i += 1) {
        numbers[i] = i + 2;
    }

    i = 0;
    var j: u32 = 0;
    while (i < size) : (i += 1) {
        if (numbers[i]) |n| {
            var k = n + n - 2;
            while (k < size) : (k += n) {
                numbers[k] = null;
            }

            buffer[j] = n;
            j += 1;
        }
    }

    return buffer[0..j];
}
