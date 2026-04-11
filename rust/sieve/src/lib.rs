use std::collections::HashSet;

pub fn primes_up_to(upper_bound: u64) -> Vec<u64> {
    let mut primes = HashSet::new();
    primes.extend(2..=upper_bound);

    let mut base = 2;
    let mut product = base + base;
    while product <= upper_bound {
        while product <= upper_bound {
            primes.remove(&product);
            product += base;
        }

        base += 1;
        product = base + base;
    }

    let mut result = primes.into_iter().collect::<Vec<_>>();

    result.sort();

    result
}
