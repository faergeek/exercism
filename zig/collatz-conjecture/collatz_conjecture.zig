pub const ComputationError = error{IllegalArgument};

pub fn steps(number: usize) anyerror!usize {
    if (number == 0) return error.IllegalArgument;

    var n = number;
    var result: usize = 0;
    while (n != 1) : (result += 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = 3 * n + 1;
        }
    }

    return result;
}
