const std = @import("std");

pub fn isArmstrongNumber(num: u128) bool {
    var gpa = std.heap.GeneralPurposeAllocator(.{}){};
    const allocator = gpa.allocator();
    defer _ = gpa.deinit();

    var list = std.ArrayList(u4).init(allocator);
    defer list.deinit();

    var n = num;
    while (n > 0) {
        list.append(@intCast(u4, n % 10)) catch unreachable;
        n /= 10;
    }

    var power = list.items.len;
    var sum: u128 = 0;
    for (list.items) |item| {
        sum += std.math.pow(u128, item, power);
    }

    return sum == num;
}
