pub fn binarySearch(comptime item: type, target: item, items: []const item) ?usize {
    if (items.len != 0) {
        var last = items.len - 1;
        var l: usize = 0;
        var h: usize = last;

        while (l <= h) {
            var m = (l + h) / 2;

            if (items[m] == target) {
                return m;
            }

            if (items[m] < target) {
                if (m == last) break;

                l = m + 1;
            } else {
                if (m == 0) break;

                h = m - 1;
            }
        }
    }

    return null;
}
