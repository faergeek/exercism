const std = @import("std");

pub fn isArmstrongNumber(num: u128) bool {
    var n = num;

    var power: u128 = 0;
    while (n > 0) : (n /= 10) {
        power += 1;
    }

    n = num;
    var sum: u128 = 0;
    while (n > 0) : (n /= 10) {
        sum += std.math.pow(u128, n % 10, power);
    }

    return sum == num;
}
