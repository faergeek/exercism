const std = @import("std");

pub const ChessboardError = error{IndexOutOfBounds};

pub fn square(index: usize) ChessboardError!u64 {
    if (index < 1 or index > 64) return ChessboardError.IndexOutOfBounds;

    var result: u64 = 1;

    var i: usize = 1;
    while (i < index) : (i += 1) {
        result *= 2;
    }

    return result;
}

pub fn total() u64 {
    var result: u64 = 0;

    var i: u8 = 1;
    while (i <= 64) : (i += 1) {
        result += square(i) catch unreachable;
    }

    return result;
}
