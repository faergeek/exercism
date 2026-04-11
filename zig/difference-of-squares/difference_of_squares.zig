pub fn squareOfSum(number: usize) usize {
    var i: usize = 1;
    var sum: usize = 0;

    while (i <= number) : (i += 1) {
        sum += i;
    }

    return sum * sum;
}

pub fn sumOfSquares(number: usize) usize {
    var i: usize = 1;
    var sum: usize = 0;

    while (i <= number) : (i += 1) {
        sum += i * i;
    }

    return sum;
}

pub fn differenceOfSquares(number: usize) usize {
    return squareOfSum(number) - sumOfSquares(number);
}
