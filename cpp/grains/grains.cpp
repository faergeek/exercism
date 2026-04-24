#include "grains.h"
#include <cstdint>

namespace grains {

unsigned long long square(int n) { return 1ULL << (n - 1); }

unsigned long long total() { return static_cast<std::uint64_t>(-1); }

} // namespace grains
